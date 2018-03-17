#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::fstream;
using Map = map<string, size_t>;

int main()
{
    Map word_count;
    fstream in("1.txt");
    string word;
    while (in >> word) {
        for (string::iterator iter = word.begin(); 
             iter != word.end(); ++iter)
        { *iter = tolower(*iter);}
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[word];
    }

    for (Map::iterator imap = word_count.begin(); imap != word_count.end(); ++imap)
        cout << (*imap).first << " occurs " << imap->second 
             << ((imap->second > 1) ? " times." : " time.") << endl;
   
}
