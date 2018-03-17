#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::cout;
using std::endl;

const double CLOCK_PER_SEC = 2808e-12;

int ViolentMatch(string& s, string& p) {
    int sLen = s.size();
    int pLen = p.size();
    int i = 0, j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            ++i;
            ++j;    
        }       
        else {
            i = i - j + 1;
            j = 0;    
        } 
    }
    if (j == pLen) return i - j;
    else return -1;
}

int main()
{
    clock_t start, end;
    start = clock();
    string T = ("xyxababcaxxxababca");
    string S = ("xabab");
    cout << ViolentMatch(T, S) << endl;
    end = clock();
    {
        double seconds = (double)(end - start) / CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
