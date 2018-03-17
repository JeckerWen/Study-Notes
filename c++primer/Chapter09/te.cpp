//! @author  @Rujie Wen
//! @date 10/1/2018
//!
//! <<C++primer>> pages:312
//!
//! Exercise 9.26 
//! 

#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;


int main()
{
    stack<int> intStack;

    for (size_t ix = 0; ix < 10; ++ix)
        intStack.push(ix);

    while (!intStack.empty()) {
        int value = intStack.top();
        cout << value << endl;
        intStack.pop();
        }
}
