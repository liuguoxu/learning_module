# 测试多线程

import time, threading

def loop_func():
    print('thread %s is running~' % threading.current_thread().name)
    n=0
    while n < 5:
        print(n)
        n += 1
        time.sleep(1)

    print('thread %s is done!' % threading.current_thread().name)



if __name__ == '__main__':
    print('thread %s is running~' % threading.current_thread().name)

    t = threading.Thread(name='little_thread', target=loop_func)

    t.start()
    t.join()

    print('thread %s is done!' % threading.current_thread().name)