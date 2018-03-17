#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

const unsigned CLOCK_PER_SEC = 1000;

int main()
{
    cilock_t start, end;
    start = clock();
    for (int i = 0; i < 100000000; i++);
    end = clock();
    {
        double seconds = (double)(end - start) * CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
