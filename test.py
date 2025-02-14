class MyClass:
    x = 10
    def __init__(self, x):
        self.x = x
obj1 = MyClass(20)
obj2 = MyClass(30)
print(obj1.x)
print(obj2.x)
print(MyClass.x)

def outer():                   # 变量作用域
    x = 10
    def inner():
        return x
    return inner
f = outer()
x = 20
print(f())

def strtest1(num):             # 不可变对象
    value = "first"
    count = set()
    for i in range(num):
        value += "X" * i
        count.add(id(value))
    print(len(count))
strtest1(3)

a = 9080589730                 # 256及以下的数字是常驻内存的
b = 9080589730
print(a is b)
a = 205
b = 205
print(a is b)

a = [[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]]   # 浅拷贝
b = a[2::]
b[0][0] = 1000
print(a)
