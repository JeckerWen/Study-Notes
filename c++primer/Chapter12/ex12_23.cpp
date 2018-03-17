#include<iostream>
#include<memory>
using std::string;

void dy_concatenate_string(const string &s1, const string &s2) {
    const size_t sz = s1.size() + s2.size();
    std::unique_ptr<int[]> con_string(new int[sz + 1]);
    size_t i = 0;
    for (auto iter = s1.cbegin(); iter != s1.cend(); ++i, ++iter)
        con_string[i] = *iter;
    for (auto iter = s2.cbegin(); iter != s2.cend(); ++i, ++iter)
        con_string[i] = *iter;
    con_string[i] = '\0'; 
    for (size_t i = 0; i != sz + 1; ++i)
        std::cout << (char)con_string[i];
    std::cout << std::endl;
    con_string.release();
}

int main()
{
   dy_concatenate_string("string", " vector"); 
}
