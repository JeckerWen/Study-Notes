#include<iostream>
#include<initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int countInt(initializer_list<int> li) {
    int sum = 0;
    for (const auto& c: li)    
        sum += c;
    return sum;
}

int main()
{
    cout << countInt({1, 2, 3, 4, 5, 6}) << endl;
    
}
