#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

bool hasUppercase(const string& s) {
    /*
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            return true;
        }
    */
    for (auto c: s)
        if (isupper(c)) return true;
    return false;
}

const string& makeLowercase(string& s) {
    /*
    for (size_t i = 0; i < s.size(); ++i) {    
        if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] += 32;
    }
    */
    for (auto& c: s)
        if (isupper(c)) c = tolower(c);
    return s;
} 

int main()
{
    string str("asdhjaAdj");
    cout << hasUppercase(str) << endl;
    cout << makeLowercase(str) << endl;
    return 0;
}
