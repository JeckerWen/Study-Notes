//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> pages:317
//!
//! Exercise 9.31
//!  Question2 
//!

#include <iostream>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;
using std::forward_list;

void FW_delete_even_insert_odd(forward_list<int>& data)
{
    auto prev = data.before_begin();
    auto curr = data.begin();
    for (curr; curr != data.end(); )
        if (*curr & 0x1) {
            curr = data.insert_after(prev, *curr);
            advance(prev, 2);
            advance(curr, 2);
        }
        else
            curr = data.erase_after(curr);        
        
}

int main()
{
    forward_list<int> forward = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FW_delete_even_insert_odd(forward);
    for (auto c: forward) cout << c << endl;
     

}
