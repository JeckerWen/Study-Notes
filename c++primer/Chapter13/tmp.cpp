#include<string>
#include<iostream>

using std::string;

class Test{
public:
    Test(string* s = nullptr, int* i = nullptr):text(s), a(i) { }
    Text(const Test& t): text(t.text), a(t.a)
    {
        t.text = nullptr;
        t.a = nullptr;
    } 

private:
    string* text;
    int* a;
};


int main()
{}
