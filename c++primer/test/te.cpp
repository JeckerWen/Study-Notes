#include <iostream>

using std::cout;
using std::endl;

class A{
public:
    A(int val = 0): value(val) {}
    int return_val() const { return value;}
    int reset_val(int ret) { 
        value = ret;
        return value;
    }
private:
    int value;    
};

int main()
{
    A a(1);
    std::cout << a.return_val() << std::endl;    
}




