#include"StrVec.h"
#include<iostream>
#include<vector>

void StrVec::push_back(const string& s) //4.
{
    chk_n_alloc(); //判断是否有空间容纳元素
    alloc.construct(first_free++, s);
}

std::pair<string*, string*> 
StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}
void StrVec::free() //3*.
{
/*
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);    
    }    */
    if (elements) {
        std::for_each(elements, first_free, 
        [this](string& rhs) { alloc.destroy(&rhs); } );    
    }
    alloc.deallocate(elements, cap - elements);
}

void StrVec::range_initialize(const string* first, const string *last)
{
    auto newdata = alloc_n_copy(first, last);    
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec& rhs) //1.
{
    range_initialize(rhs.begin(), rhs.end());
    std::cout << "拷贝构造函数"  << std::endl;
}

StrVec::StrVec(std::initializer_list<string> li)
{
    range_initialize(li.begin(), li.end());    
}

StrVec::~StrVec() { free();} //3.

StrVec& StrVec::operator=(const StrVec &rhs) //2.
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    std::cout << "拷贝赋值运算符"  << std::endl;
    return *this;    
}

void StrVec::alloc_n_move(size_t new_cap) //5*.
{
   auto newdata = alloc.allocate(new_cap);
   auto dest = newdata;
   auto elem = elements;
   for (size_t i = 0; i != size(); ++i)
       alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap; 
}

void StrVec::reallocate() //4*.
{
   auto newcapacity = size() ? 2 * size() : 1;
   alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count, const string& s)
{
    if (count > size()) {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);    
    }    
    else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);    
    }
}

void StrVec::resize(size_t count)
{
    resize(count, string());    
}

int main()
{
    std::vector<StrVec> vec;  
    StrVec s1("hello");
    StrVec s2 = s1;  
    vec.push_back(s1);  
    vec.push_back(s2);  
    return 0; 
}
