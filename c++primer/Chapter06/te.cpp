#include<iostream>

using std::cout;
using std::endl;


void print(const char word[], size_t size) {
    if (sizeof(word) < 10)
        std::cerr << "Error: " << __FILE__ << " : in function "
             << __func__ 
             << " at line " << __LINE__ << endl
             << " at " << __TIME__ << endl 
             << " Word read was \"" << word 
             << "\" : Length too short" << endl;
}

int main()
{
    char *word = "abs";
    print(word, 8);
        
}
