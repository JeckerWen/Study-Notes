#ifndef CP5_ex12_19_h 
#define CP5_ex12_19_h 

#include<iostream>
#include<vector>
#include<string>
#include<memory>

using std::string;
using std::vector;

class StrBlobPtr;
class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();
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

/*
class StrBolbPtr {
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
    string& deref() const {
        auto p = check(curr, "dereference past end.");
        return (*p)[curr];    
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;    
    }

private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if(i >= ret->size())
            throw std::out_of_range(msg);
        return ret;    
    }    
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};
*/
class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    string& deref() const;
      StrBlobPtr& incr();

private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) 
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) 
            throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;

};

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];    
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;    
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);    
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

#endif


















