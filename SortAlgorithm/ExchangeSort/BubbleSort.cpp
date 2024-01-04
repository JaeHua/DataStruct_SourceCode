//
// Created by jjh on 2024/1/4.
//
//
/*
 * 冒泡排序，大一梦开始的地方~
 **/
#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int>&v)
{
    int n = v.size();
    for(int i = 0; i < n - 1;i++)
    {
        bool flag = true;
        for(int j = n-1;j>i;j--)
            if(v[j]<v[j-1])
            {
                swap(v[j],v[j-1]);
                flag = false;
            }
        if(flag)break;
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    BubbleSort(data);
    for(int d : data)cout<<d<<" ";
    return 0;
}