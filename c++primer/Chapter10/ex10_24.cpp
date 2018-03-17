#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using namespace std::placeholders;

bool check_size(size_t sz, const string &s)
{
    return sz > s.size();    
}

void biggeis(const vector<int> &words, const string &str)
{
    auto wc = find_if(words.cbegin(), words.end(), bind(check_size, _1, str));
    if (wc != words.end())
        cout << *wc << endl;
    else
        cout << "Not Found!" << endl;
}

int main() 
{
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str("123456");
    biggeis(vec, str);
    return 0;    
}
