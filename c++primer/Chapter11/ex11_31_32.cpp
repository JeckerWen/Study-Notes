#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::multimap;
using std::set;
using std::map;

int main()
{
    std::multimap<string, string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };
    /*---------ex11_31--------
    string author = "pezy";
    string word = "CP5";
    auto found = authors.find(author);
    auto count = authors.count(author);

    while (count)
    {
        if (found->second == word) {
            authors.erase(found);
            break;   
        }
        ++found;
        --count;
    }
    for (auto pos = authors.cbegin(); pos != authors.cend(); ++pos)
        cout << "Author name: " << pos->first << " Words: " << pos->second << endl;
    */

    //---------ex11_32---------
    map<string, set<string>> order_authors;
    for (const auto &author: authors)
        order_authors[author.first].insert(author.second);
    for (const auto &order_author: order_authors) 
    {
        cout << "Author name is: " << order_author.first;
        cout << "   Works: " ;
        for (const auto &order_work: order_author.second)
        cout << "<<" << order_work << ">>" << " ";
        cout << endl;
    }


}


















