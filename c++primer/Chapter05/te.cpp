#include<iostream>

using std::cout;
using std::endl;

int fact(int val) {
    int tal = 1;
    while (val > 0)
        tal *= val--;
    return tal;    
}
int main()
{
    cout << fact(5) << endl;;
}
