#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

const double CLOCK_PER_SEC = 2808;

bool Brute(string& T, string& S)
{
    auto iterT = T.begin();
    auto iterS = S.begin();
    cout << "T = " << T << endl;
    cout << "S = " << S << endl;
    while ( (iterS != S.end()) && (iterT != T.end()) ) {
        if (*iterS == *iterT) {
            cout << "*iterT is :" << *iterT << endl;
            cout << "*iterS is :" << *iterS << endl;
            ++iterS;
            ++iterT;
                        }
        else {
            ++iterT;
            auto iterS = S.begin();
            }
        }
    if (*(iterS - 1) == *(iterT - 1)) return true;
    return false;
}


int main()
{
    clock_t start, end;
    start = clock();
    string T = ("xyxababcaxxxababca");
    string S = ("xabab");
    cout << "Result is :" << (int)Brute(T, S) << endl;
    end = clock();
    {
        double seconds = (double)(end - start) / CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
