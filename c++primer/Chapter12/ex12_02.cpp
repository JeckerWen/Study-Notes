#include<iostream>
#include<vector>
#include<string>
#include<memory>


class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    size_type size() { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;



private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> li):
         data(std::make_shared<std::vector<std::string>> (li)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);    
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");    
    data->pop_back();
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");    
    data->front();
}
std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");    
    data->back();
}
const std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");    
    data->front();
}   
const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");    
    data->back();
}


