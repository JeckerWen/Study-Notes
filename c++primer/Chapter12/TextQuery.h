#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
#include<sstream>
#include<map>
#include<set>

using std::vector;
using std::string;
using std::map;
using std::set;
using std::cout;
using std::endl;

using line_no = vector<string>::size_type;

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

private:
    std::shared_ptr<vector<string>> file; //file is a shared_ptr;
    map<string, std::shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is): file(new vector<string>) {
    string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;    
        std::istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);    
        }
    }    
}

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<vector<string>> f):
                sought(s), lines(p), file(f) {}
private:
    string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<vector<string>> file;   
};

QueryResult
TextQuery::query(const string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);    
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? "times." : "time.") << endl;    
    for (auto num: *qr.lines)
        os << "\t(line " << num + 1 << "): "
           << *(qr.file->begin() + num) << endl;
    return os;
}

void runQueries(std::ifstream &infile) 
{
    TextQuery tq(infile);
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;    
    }    
}

