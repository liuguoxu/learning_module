#测试fork子进程

import os

print('process id is:%s' % os.getpid())

pid = os.fork()
if pid == 0:
    print("i am child process, my pid is %s, my parent pid is %s" % (os.getpid(), os.getppid()))
else:
    print("i am father process:%s, my child pid is %s" % (os.getpid(), pid))