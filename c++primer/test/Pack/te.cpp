#include <iostream>
#include <ctime>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const unsigned CLOCK_PER_SEC = 1000;

int main()
{
    clock_t start, end;
    start = clock();
    vector<double> vec1{2};
    vector<double> vec2{3};
    double a = *vec1.begin() / *vec2.begin();
    cout << a << endl;
    end = clock();
    {
        double seconds = (double)(end - start) * CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
