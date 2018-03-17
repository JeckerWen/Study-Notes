//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> pages:314
//!
//! Exercise 9.27 
//! 

#include <iostream>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;
using std::forward_list;



int main()
{
    forward_list<int> flst  = {1, 2, 3, 4, 5, 6, 7, 8};
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while (curr != flst.end())
        if (*curr & 0x1)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
            }
    for (auto c: flst) cout << c << endl;
}
