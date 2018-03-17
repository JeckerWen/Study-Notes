#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>

using std::cout;
using std::endl;
using std::vector;

int main() 
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < 10; ++i) 
        vec.push_back(rand() % 10);
    for (auto c: vec) cout << c << " ";
    cout << endl;
    int val = rand() % 10;
    cout << "val " << val << " : " << count(vec.cbegin(), vec.cend(), val) << endl;


    return 0;    
}
