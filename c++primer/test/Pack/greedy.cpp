#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
const unsigned CLOCK_PER_SEC = 1000;
const double MaxPack = 15.0;
const int ITEM_NUM = 6;
struct Goods
{
    double Weight;
    double Value;
    double PerVal;;    
};
int cmp(Goods const& a, Goods const& b)
{
    if (a.PerVal < b.PerVal) return 0;
    else return 1;    }
double Greedy(Goods item[],int item_num, const double MaxPack)
{
    double CurrPack = 0.0;
    double MaxValue = 0.0;
    for (int i = 0; i < item_num; ++i)
    {
        if (CurrPack < MaxPack) {
            if (item[i].Weight <= (MaxPack - CurrPack)) {
                CurrPack += item[i].Weight;
                MaxValue += item[i].Value;} 
        }
    }
    return MaxValue;
} 


int main()
{
    clock_t start, end;
    start = clock();
    Goods item[ITEM_NUM];
    for (int i = 0; i < ITEM_NUM; ++i) {
        cin >> item[i].Weight >> item[i].Value; 
        item[i].PerVal = item[i].Value /item[i].Weight;
    }
    sort(item, item + ITEM_NUM, cmp);
    cout << "The max value is: " << Greedy(item, ITEM_NUM, MaxPack) << endl;


    /*
    vector<double> W = {1.0, 3.0, 3.0, 6.0, 5.0, 4.0};
    vector<double> V = {1.0, 1.0, 2.0, 5.0, 4.0, 6.0};
    Greedy(W, V, 15);
    */
    end = clock();
    {
        double seconds = (double)(end - start) * CLOCK_PER_SEC;
        cout << "Use time is:" << seconds << endl;    
    }

}
