__author__ = 'gxliu'

import sys

def do_hello(name):
    print('hello %s!' % name)

def hello(name):
    arg = sys.argv

    if len(arg) == 1:
        do_hello('world')
    elif len(arg) == 2:
        do_hello(arg[1])
    elif len(arg) > 2:
        print('too many arguments!')
    else:
        do_hello(name)


if __name__ == '__main__':
    hello('test')