#include<iostream>
#include<algorithm>
#include<vector>
#include "Sales_data.h"

using std::cout;
using std::endl;



int main() 
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> vec{ d1, d2, d3, d4, d5 };

    sort(vec.begin(), vec.end(),
        [](const Sales_data &s1, const Sales_data &s2)
        { return s1.isbn() > s2.isbn();});

    for (const auto &c : vec)
        cout << c.isbn() << " ";
    cout << endl;

    return 0;    
}
