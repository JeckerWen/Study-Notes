#ifndef CP5_EX_13_39_H_
#define CP5_EX_13_39_H_

#include<memory>
#include<string>
#include<initializer_list>
#include<algorithm>

using std::string;

class StrVec{
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&); // 1.
    StrVec(std::initializer_list<string>);
    StrVec& operator=(const StrVec&); //2.
    ~StrVec(); //3.

    void push_back(const string&); //4.
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);

private:
    std::pair<string*, string*>
    alloc_n_copy(const string*, const string* ); //2*.
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();    
    } // 1*.
    void range_initialize(const string*, const string*);
    void free(); //3*.
    void reallocate(); //4*.
    void alloc_n_move(size_t new_cap);//5*.

private:
    std::allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;
};
#endif
