#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

const unsigned CLOCK_PER_SEC = 2808;

vector<int> getNext(string T)
{
    vector<int> next(T.size(), 0);
    next[0] = -1;
    int k = 0;
    for (int j = 2; j < T.size(); ++j) {
        while (k > 0 && T[j - 1] != T[k])
            k = next[k];
        if (T[j - 1] == T[k])
            ++k;
        next[j] = k;    
    }    
}

int KMP (string  S, string  T) 
{
    vector<int> next = getNext(T);
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0') {
        if (S[i] == T[j]) {
            ++i; 
            ++j; 
        }    
        else       
            j = next[j];    

        if (j == -1) {
            ++i;
            ++j;
        }
        if (T[j] == '\0')
            return i - j;
        else
            return -1;
       
    }    
}

int main()
{
    clock_t start, end;
    start = clock();
    string T = ("xyxababcaxxxababca");
    string S = ("xabab");
    cout << KMP(S, T) << endl;
    
    end = clock();
    {
        double seconds = (double)(end - start) / CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }
    

}
