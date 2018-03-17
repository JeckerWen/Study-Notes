#include<iostream>
#include"TextQuery.h"
#include<fstream>

int main()
{
    std::ifstream input("./data/letter.txt");
    runQueries(input);
    
}
