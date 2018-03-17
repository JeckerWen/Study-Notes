//
//  ex13_13.cpp
//  CP5
//
//  Created by pezy on 1/13/15.
//
//  A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:
//  struct X {
//    X() { std::cout << "X()" << std::endl; }
//    X(const X&) { std::cout << "X(const X&)" << std::endl; }
//  };
//  Add the copy-assignment operator and destructor to X and write a program using X objects in various ways:
//  Pass them as nonreference and reference parameters;
//  dynamically allocate them;
//  put them in containers; and so forth.
//  Study the output until you are certain you understand when and why each copy-control member is used.
//  As you read the output, remember that the compiler can omit calls to the copy constructor.

#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)// 2.
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);// 3.
    vec.push_back(x);// 4.
} // 5, 6, 7.

int main()
{
    X *px = new X();// 1.
    f(*px, *px);
    delete px;// 8.
/*****Result:
    1.X();
    2.X(const X&)
    3.X(const X&)
    4.X(const X&)
    5.~X()
    6.~X()
    7.~X()
    8.~X()
*************/
    return 0;
}











