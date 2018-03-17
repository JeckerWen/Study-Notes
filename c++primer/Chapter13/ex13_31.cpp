#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::string;

class HasPtr{
public:
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
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
    void show() const {
         std::cout << *ps << std::endl;
    }

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

bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
    return *lhs.ps < *rhs.ps;
}

int main()
{
    HasPtr s{ "s" }, a{ "a" }, c{ "c" };
    std::vector<HasPtr> vec{ s, a, c };
    std::sort(vec.begin(), vec.end());

    for (auto const& elem : vec) elem.show();
    return 0;
}
