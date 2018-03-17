#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() 
{
    int a = 5;
    auto check = [&a]() { return a > 0 ? --a : a;};
    while (check())
        cout << a << " ";
    cout << a << endl;
}
