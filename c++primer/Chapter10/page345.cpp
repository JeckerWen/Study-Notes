#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();    
}

int main() 
{
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "w", "w"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    for (auto c: vec)
        cout << c << " ";
    cout << endl;

    return 0;    
}
