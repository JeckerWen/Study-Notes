#include<iostream>
#include<string>

using namespace std;

void func1(int* num)
{
    cout << "this is the ptr function..." << endl;    
}

void func(int num)
{
    cout << "this is the normal function..." << endl;    
}

int main()
{
    func1(NULL);    
}
