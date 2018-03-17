#include<iostream>
#include<string>

using std::string;

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string& s = string()):
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp): ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& hp) {
       auto new_p = new string(*hp.ps);
       delete ps;
       ps = new_p;
       i = hp.i;
       return *this;
    }
    ~HasPtr() {
       delete ps;    
    }
    void exchange_i(int t) { i = t;}
    void show() { std::cout << *ps << i  << std::endl;}

private:
    string* ps;
    int i;
        
};

inline
void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

int main()
{
    HasPtr h1("lalala~"), h2;
    h1.exchange_i(2);
    swap(h1, h2);
    h2.show();
}
