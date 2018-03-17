#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::cout;
using std::endl;

const unsigned CLOCK_PER_SEC = 1000;

int SundaySearch(string T, string S)
{
    int i = 0, j = 0, k;
    int m = S.size();
    
    if (T.size() <= 0 || S.size() <= 0)
        return -1;
    for (; i < T.size(); ) {
        if (T[i] != S[j]) {
            for (k = S.size() - 1; k >= 0; --k) {
                if (S[k] == T[m])
                    break;
                }
                i = m - k;
                j = 0;
                m = i + S.size();
            }    
            else {
                if (j == S.size() - 1)
                    return i - j;
                ++i;
                ++j;
            }
    }   
    return -1;
}

int main()
{
    clock_t start, end;
    start = clock();
    string T = ("xyxababcaxxxababca");
    string S = ("xabab");
    end = clock();
    {
        double seconds = (double)(end - start) * CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
