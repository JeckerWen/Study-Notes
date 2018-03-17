//! @author  @Rujie Wen
//! @date 11/1/2018
//!
//! <<C++primer>> pages:320
//!
//! Exercise 9.40
//! 
//! Anwers:
//! After insert: 256 capacity is: 1024
//! After insert: 512 capacity is: 1024
//! After insert: 1000 capacity is: 1024
//! After insert: 1048 capacity is: 2048
//!
//!
//! 

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void func(vector<string>::size_type n)
{
    vector<string> svec;
    svec.reserve(1024);
    string word = "a";
    for (vector<string>::size_type i = 0; i < n; ++i)
        svec.push_back(word);
    cout << "After insert: " << n;
    cout <<  " capacity is: " <<svec.capacity() << endl;
}

int main()
{
    func(256);
    func(512);
    func(1000);
    func(1048);
}
