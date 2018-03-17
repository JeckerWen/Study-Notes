#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<cctype>

#include"StrBlob.h"

using std::vector;
using std::string;
using std::map;
using std::set;
using std::cout;
using std::endl;

using line_no = StrBlob::size_type;

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

private:
    StrBlob file; //file is a shared_ptr;
    map<string, std::shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is)/*: file(new vector<string>)*/ {
    line_no lineNo(0);
    for (string line; std::getline(is, line); ++lineNo) {
        file.push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), 
                                std::back_inserter(word), ispunct);
            auto &nos = wm[word];
            if (!nos)
                 nos.reset(new set<line_no>);
            nos->insert(lineNo);
        }
    }
    /*
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
    */   
}

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, std::shared_ptr<std::set<line_no>> p,
                const StrBlob& f):
                sought(s), lines(p), file(f) {}
private:
    string sought;
    std::shared_ptr<std::set<line_no>> lines;
    StrBlob file;   
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
    for (auto i: *qr.lines) {
        StrBlobPtr p(qr.file, i);
        os << "\t(line " << i + 1 << "): "
           << p.deref() << endl;
    }
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
#endif
