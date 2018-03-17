//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> page:312
//!
//! Exercise 9.26 
//! 

#include <iostream>
#include <list>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;


int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    list<int> odd(ia, ia + 9);
    vector<int> even(odd.begin(), odd.end());

    auto iter_odd = odd.begin();
    auto iter_even = even.begin();

    while (iter_odd != odd.end())
        if (*iter_odd & 0x1)
            iter_odd = odd.erase(iter_odd);
        else
            ++iter_odd;

    while (iter_even != even.end())
        if (*iter_even & 0x1)
            ++iter_even;
        else
            iter_even = even.erase(iter_even);

    for (auto c: odd) cout << c << endl;
    cout << endl;
    for (auto c: even) cout << c << endl;
    cout << endl;
}
