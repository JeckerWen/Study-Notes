#include<iostream>
#include<memory>
#include<string>

using std::allocator;
using std::string;

int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
    string str;
    while (q < p + 10 && std::cin >> str)
        *q++ = str;
    while (q != p) {
        std::cout << *(--q) << " ";
        alloc.destroy(q);
    }
    std::cout << std::endl;
    alloc.deallocate(p, 10);
}
