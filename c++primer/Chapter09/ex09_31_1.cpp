//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> pages:317
//!
//! Exercise 9.31
//!  Question1
//! 

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void list_delete_even_insert_odd(list<int>& data)
{
    auto iter = data.begin();
    while (iter != data.end())
        if (*iter & 0x1) { //*iter is odd.
            iter = data.insert(iter, *iter);    
            advance(iter, 2);
        }
        else 
            iter = data.erase(iter);
}

int main()
{
    list<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list_delete_even_insert_odd(vec);
       for (auto c: vec) cout << c << endl;
   
}
