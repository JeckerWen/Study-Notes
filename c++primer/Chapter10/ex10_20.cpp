#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() 
{
    string d1 = "sdjaklg", d2 = "djf", d3 = "dnfjkaanf", d4 = "asdadklf", d5 = "sdv", d6 = "sdanj";
    vector<string> vec{d1, d2, d3, d4, d5, d6};
    auto count = count_if(vec.cbegin(), vec.cend(), [](string s){ return s.size() > 6;});
    cout << count << endl;

}
