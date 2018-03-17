#include<iostream>
#include<vector>
#include<algorithm>


using std::vector;
using std::sort;

class Foo{
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;    
};


Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl;    
    return *this;
}

Foo Foo::sorted() const & {
    
    std::cout << "&" << std::endl;    
    return Foo(*this).sorted();
}

int main()
{
    Foo().sorted(); // call "&&"
    std::cout << "------------1-------------\n";
    Foo f;
    std::cout << "------------2-------------\n";
    f.sorted(); // call "const &"
}
