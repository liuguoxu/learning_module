#include "command.hpp"
#include <iostream>

void func()
{
	const char *file = "/bin/cat";
	char *argv[3] = {(char *)file, (char *)"/home/jere/workspace/learning_module/cpp_learn/command/proc.c", NULL};
	//char *argv[3] = {(char *)file,  NULL};
	char *env[1] = {NULL};

	CommandExecve cmd(file, argv, env);

	//Command cmd("cat \"/home/jere/workspace/learning_module/cpp_learn/command/proc.c\"");

	try {
		auto const& res = cmd.execute();
		for (auto &item : res) {
			std::cout << item << std::endl;
		}

	} catch(std:: exception &e) {
		std::cout << "exception:" << e.what() << std::endl;
	}

	std::cout << "execute success~" << std::endl;

}


int main()
{
	func();

	std::cout << "after func" << std::endl;

	return 0;
}
