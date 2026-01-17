#include <iostream>
#include <memory>
#include <stdexcept>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

class Person {
public:
    Person() {
        cout << "构造函数" << endl;
    }
    ~Person() {
        cout << "析构函数" << endl;
    }
};

int test() {
    cout << "test函数中" << endl;
    throw std::exception();
    return 100;
}

void do_logic(unique_ptr<Person> p, int number) {}

int main() {
    try {
        // 不同的编译器，函数调用的参数的求值顺序可能不同
        // 有的编译器会先调用 new Person，然后调用test()，抛出异常，造成内存泄漏
        // Linux 下用 g++测试时并未出现内存泄漏
        // do_logic(unique_ptr<Person>(new Person), test());

        do_logic(make_unique<Person>(), test());
    } catch (...) {
        cout << "捕获到异常" << endl;
    }
    return 0;
}
