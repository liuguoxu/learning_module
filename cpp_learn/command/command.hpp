#ifndef IK_DATA_CAPTURE_COMMAND_H_
#define IK_DATA_CAPTURE_COMMAND_H_
#include <string>
#include <vector>
#include <stdexcept>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

using std::string;
using std::vector;

class ICommand {
public:
	virtual ~ICommand()
	{}

	virtual vector<string> execute() noexcept(false) = 0;
};

class Command: public ICommand {
public:
	Command(const char* cmd, const char* mode = "r")
		: cmd_(cmd)
		, m_(mode)
	{}

	~Command()
	{
		if (stream_) {
			pclose(stream_);
		}
	}

public:
	vector<string> execute() noexcept(false)
	{
		vector<string> res;

		stream_ = popen(cmd_.c_str(), m_.c_str());
		if (!stream_) {
			string err(strerror(errno));
			throw std::runtime_error("popen failed, " + err);
		}

		if (stream_) {
			char* line = NULL;
			size_t len = 0;

			while (::getline(&line, &len, stream_) != -1) {
				res.push_back(line);
			}

			free(line);
		}

		return res;
	}

	// before re-execute the same command, you should invoke reset firstly to clear the fd
	void reset()
	{
		if (stream_) {
			pclose(stream_);
		}
	}

private:
	FILE* stream_;
	string cmd_;
	string m_;
};

// fork and execve
class CommandExecve :public ICommand{
public:
	CommandExecve(const char * cmd, char* const* argv, char* const* envp)
		: cmd_(cmd)
		,argv_(argv)
		, envp_(envp)
	{}

	~ CommandExecve()
	{}

public:
	vector<string> execute() noexcept(false)
	{
		vector<string> res;
		int pfds[2];
		if (pipe(pfds) < 0) {
			throw std::runtime_error("pipe error");
		}

		pid_t pid = fork();
		if (pid < 0) {
			throw std::runtime_error("fork error");
		}

		if (pid == 0) {
			//close fds derived from parent
			for (int i = STDERR_FILENO + 1; i < getdtablesize(); ++i) {
				if (i != pfds[1])
					close(i);
			}

			if (pfds[1] != STDOUT_FILENO) {
				dup2(pfds[1], STDOUT_FILENO);
				close(pfds[1]);
			}

			if (execve(cmd_.c_str(), argv_, envp_) != 0) {
				exit(-1);
			}

			exit(0);
		} else if (pid > 0) {
			close(pfds[1]);

			FILE* fp;
			if ( (fp = fdopen(pfds[0], "r")) == NULL) {
				throw std::runtime_error("fdopen error");
			}

			char* line = NULL;
			size_t len = 0;

			while (::getline(&line, &len, fp) != -1) {
				res.push_back(line);
			}
			free(line);
			fclose(fp);

			int st = 0;
			if (waitpid(pid, &st, 0) == -1) {
				throw std::runtime_error("script execve error");
			}

			if (!WIFEXITED(st)) {
				throw std::runtime_error("script execve error");
			}
		}

		return res;
	}
private:
	string cmd_;
	char* const*argv_;
	char* const*envp_;
};

#endif
