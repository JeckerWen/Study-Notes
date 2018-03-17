//! @author  @Rujie Wen
//! @date 13/1/2018
//!
//! <<C++primer>> pages:328
//!
//! Exercise 9.50
//! 

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

// vector<string> --> sum of int;
int sum_string_to_int(vector<string> const& vec)
{
    int total = 0;
    for (auto c: vec)
        total += stoi(c);
    return total;
}

// vector<string> --> sum of double;
double sum_string_to_double(vector<string> const& vec)
{
    double total = 0.0;
    for (auto c: vec)
        total += stod(c);
    return total;    
}

int main()
{
    vector<string> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(to_string(i));
    cout << sum_string_to_int(vec) << endl;
    cout << sum_string_to_double(vec) << endl;
}
