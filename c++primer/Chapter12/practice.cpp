#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<set>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using size_type = vector<string>::size_type;


int main()
{
    std::ifstream file("./data/letter.txt");
    vector<string> input;
    std::map<string, std::set<size_type>> dictionary;
    size_type lineNo(0);

    for (string line; std::getline(file, line); ++lineNo) {
        input.push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
           std::remove_copy_if(text.cbegin(), text.cend(),
                              std::back_inserter(word), ispunct);
           dictionary[word].insert(lineNo);
        }    
    }

    while (true) {
        cout << "Pls Enter the word that you want to look for, or 'q' to quit:";
        string word;
        if (!(std::cin >> word) || word == "q") break;
        auto found = dictionary.find(word);
        if (found != dictionary.end()) {
            cout << word << " occurs " << found->second.size() << (found->second.size() > 1 ? " times." : " time.") << endl;
            for (const auto& i: found->second)
                cout << "\t(line " << i + 1 << "): " << input.at(i) << endl;
        }
        else cout << word << " occurs 0 time." << endl;
    }
}


























