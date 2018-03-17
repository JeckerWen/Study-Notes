//! @author  @Rujie Wen
//! @date 12/1/2018
//!
//! <<C++primer>> pages:327
//!
//! Exercise 9.47-a
//! 

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
    string str("ab2c3d7R4E6");
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string numbers("0123456789");

    cout << "Numberic characters: ";
    for (string::size_type pos = 0; ((pos = str.find_first_of(numbers, pos)) != 
         string::npos); ++pos)
        cout << "elements is " << str[pos] << " index is " << pos << endl;
    cout << "\nAlphabetic characters: ";
    for (string::size_type pos = 0; ((pos = str.find_first_of(alphabet, pos))!=
         string::npos); ++pos)
        cout << "elements is " << str[pos] << " index is " << pos << endl;

    return 0;
}
