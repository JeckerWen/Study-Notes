
#include "te.h"
#include <iostream>

int main()
{
    std::ifstream file("./data/storyDataFile.txt");
    runQueries(file);
}
