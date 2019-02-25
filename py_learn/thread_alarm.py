import threading
import time
import signal
from functools import wraps

def f1():
    while True:
        time.sleep(1)
        print('f1')


def f2():
    while True:
        time.sleep(2)
        print('f2')


th1 = threading.Thread(target=f1, name='f1')
th1.daemon = True
th1.start()

th2 = threading.Thread(target=f2, name='f2')
th2.daemon = True
th2.start()


def wrap(func):
    def handle(signum, frame):  # 收到信号 SIGALRM 后的回调函数，第一个参数是信号的数字，第二个参数是the interrupted stack frame.
        print(signum)
        raise RuntimeError

    @wraps(func)
    def to_do(*args, **kwargs):
        try:
            ret = signal.signal(signal.SIGALRM, handle)  # 设置信号和回调函数
            print(ret)
            signal.alarm(1)  # 设置 num 秒的闹钟
            print('start alarm signal.')
            r = func(*args, **kwargs)
            print('close alarm signal.')
            signal.alarm(0)  # 关闭闹钟
            return r
        except RuntimeError as e:
            print('eeeee')

    return to_do


@wrap
def my_func():
    print('in my_func')
    time.sleep(2)
    print('out my_func')

my_func()
time.sleep(10)
