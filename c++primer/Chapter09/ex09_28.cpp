//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> pages:312
//!
//! Exercise 9.28
//! 

#include <iostream>
#include <string>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::forward_list;

int FW_insert(forward_list<string>& flst, const string& str1, const string& str2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    
    while (curr != flst.end())
        if (*curr == str1) {
            curr = flst.insert_after(curr, str2);
            return 1;
        }
        else {
            prev = curr;
            ++curr;    
        }
    flst.insert_after(curr, str2);

    
}

int main()
{
    forward_list<string> flst{"a", "bb", "ccc"};
    string str1 = "a";
    string str2 = "dddd";
    FW_insert(flst, str1, str2);
    for (auto iter = flst.begin(); iter != flst.end(); ++iter)
        cout << *iter << endl;
        

}
