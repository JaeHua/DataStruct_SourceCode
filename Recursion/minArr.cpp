//
// Created by ½ͺ½άξό on 2023/11/8.
//
#include <iostream>
#include <vector>
using namespace std;
int minArr(vector<int>a,int index)
{
    if(index == 0)
        return a[0];
    else
    {
        return min(a[index], minArr(a,index-1));
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<"The minnum of a is "<<minArr(a,n-1)<<endl;
    return 0;
}