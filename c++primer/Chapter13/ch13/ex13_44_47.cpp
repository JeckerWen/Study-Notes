#include "ex13_44_47.h"
#include <algorithm>
#include <iostream>
#include<vector>

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator = (const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

void foo(String x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    std::cout << "-----------1-----------------" << std::endl;
    String s2(s0);
    std::cout << "-----------2-----------------" << std::endl;
    String s3 = s1;
    std::cout << "-----------3-----------------" << std::endl;
    String s4(text);
    std::cout << "-----------4-----------------" << std::endl;
    s2 = s1;
    std::cout << "-----------5-----------------" << std::endl;

    foo(s1);
    std::cout << "-----------6-----------------" << std::endl;
    bar(s1);
    std::cout << "-----------7-----------------" << std::endl;
    foo("temporary");
    std::cout << "-----------8-----------------" << std::endl;
    bar("temporary");
    std::cout << "-----------9-----------------" << std::endl;
    String s5 = baz();
    std::cout << "-----------10----------------" << std::endl;

    std::vector<String> svec;
    svec.reserve(8);
    std::cout << "-----------11----------------" << std::endl;
    svec.push_back(s0);
    std::cout << "-----------12----------------" << std::endl;
    svec.push_back(s1);
    std::cout << "-----------13----------------" << std::endl;
    svec.push_back(s2);
    std::cout << "-----------14----------------" << std::endl;
    svec.push_back(s3);
    std::cout << "-----------15----------------" << std::endl;
    svec.push_back(s4);
    std::cout << "-----------16----------------" << std::endl;
    svec.push_back(s5);
    std::cout << "-----------17----------------" << std::endl;
    svec.push_back(baz());
    std::cout << "-----------18----------------" << std::endl;
    svec.push_back("good job");
    std::cout << "-----------19----------------" << std::endl;

    for (const auto &s : svec) {
        std::cout << s.c_str() << std::endl;
    }
}
