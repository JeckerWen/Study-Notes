#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

/*
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() > s2.size();    
}
*/

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;    
}
//page:349 complete code of biggies.
void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), 
        [](const string &s1, const string &s2) 
        { return s1.size() < s2.size();});    
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
        { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count + 1  << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer." << endl;
    for_each(wc, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;

}
 

int main() 
{
    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "w", "w"};
    vector<string>::size_type sz = 4;
    biggies(vec, sz); 
    return 0;    
}
