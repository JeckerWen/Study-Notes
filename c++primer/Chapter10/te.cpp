#include<iostream>
#include<list>
#include<algorithm>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::list;

int main() 
{
    list<int> lst{22, 33, 44};
    list<int> lst2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    lst.splice(lst.begin(), lst2);
    for (const auto &c : lst)
        cout << c << endl;
    return 0;    
}
