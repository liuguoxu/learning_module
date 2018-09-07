# for class test


class Animal():
    def run(self):
        print('an animal is running~')


class Dog(Animal):
    def __init__(self, name):
        self.name = name

    def run(self):
        print('my name is %s, I am running~' % self.name)


def letsRun(an):
    an.run()


teddy = Dog('teddy')
# 为类实例定义的属性只有这个实例拥有，其他类实例无此属性
teddy.age = 2

unknown = Animal()

letsRun(teddy)
letsRun(unknown)



print(teddy.age)

jinmao = Dog('jinmao')

