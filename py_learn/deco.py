# 装饰器

# 定义一个装饰器函数
def myDeco(func):
    def wrapper(x,y):
        print('nums to be added:',x,y)
        r = func(x,y)
        print('after my decorate func')
        return r

    return wrapper


# 使用装饰器装饰函数
@myDeco
def add(x, y):
    return x+y


print(add(1, 2))
