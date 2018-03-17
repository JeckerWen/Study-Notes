#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool check_size(const string& s, vector<string>::size_type sz)
{
    return s.size() > sz;    
}

void biggeis(const vector<string> &words, vector<string>::size_type sz)
{
    auto wc = find_if(words.cbegin(), words.end(), bind(check_size, std::placeholders::_1, sz));
    cout << *wc << endl;
}

int main() 
{
    string d1 = "sdjaklg", d2 = "djf", d3 = "dnfjkaanf", d4 = "asdadklf", d5 = "sdv", d6 = "sdanj";
    vector<string> vec{d1, d2, d3, d4, d5, d6};
    biggeis(vec, 6);

    return 0;    
}
