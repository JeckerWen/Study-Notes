#include<stdio.h>  
#include<iostream>  
using std::cout;
using std::endl;
using std::max;  
using std::min;
int tableTwo[10][100];  
int flag[10] = {-1};   
int KnapsackTwo(int v[],int w[],int c,int n)
 {    
    int jMax = min(w[n]-1,c);   
    for(int j = 0; j<jMax; ++j)
        tableTwo[n][j] = 0;   
    for(int j = w[n]; j <= c; ++j)
        tableTwo[n][j] = v[n];
        for(int i = n - 1; i > 1; --i) {  
            jMax = min(w[i], c);  
        for(int j = 0; j <= jMax; ++j)
            tableTwo[i][j] = tableTwo[i+1][j];  
        for(int j = w[i]; j <= c; ++j)
            tableTwo[i][j] = max(tableTwo[i+1][j], 
            tableTwo[i+1][j-w[i]]+v[i]);   }  
    tableTwo[1][c] = tableTwo[2][c];  
    if (c >= w[1]) 
        tableTwo[1][c] = max(tableTwo[1][c], 
        tableTwo[2][c-w[1]]+v[1]);   
    return tableTwo[1][c];   
  }  
 void Traceback(int w[], int c, int n){  
    for (int i = 1; i < n; ++i){  
        if (tableTwo[i][c] == tableTwo[i+1][c])
            flag[i] = 0;  
        else {  
            flag[i] = 1;  
            c -= w[i];      }  
    }  
    flag[n] = tableTwo[n][c] ? 1 : 0;  }  
   
 int main(){  
    int weight[6] = {1, 3, 3, 6, 5, 4};  
    int value[6] = {1, 1, 2, 5, 4, 6};
    int c = 10;  
    cout<<"The max values is："<< KnapsackTwo(value, weight, c, 5) << endl;  
    Traceback(weight, c, 5);  
    cout<<"The optimal solution is：";   
    for(int i = 1; i < 5 + 1; ++i)
        cout << flag[i] <<" ";  
    cout << endl;  
    for (int i = 1; i < 6; ++i){  
        for(int j = 0;j < 11; ++j){  
            printf("%2d ", tableTwo[i][j]);
        }  
        cout << endl;  
    }  
    return 0;  
      
 }  
