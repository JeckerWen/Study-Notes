#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

int main() 
{
    string d1 = "aa", d2 = "aa", d3 = "dnfjkaanf", d4 = "asdadklf", d5 = "sdv", d6 = "sdanj";
    vector<string> vec{d1, d2, d3, d4, d5, d6};
    list<string> lst;
    unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin())) ;
    for (const auto &c : lst)
        cout << c << endl;
    return 0;    
}
