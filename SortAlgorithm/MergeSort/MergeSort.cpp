//
// Created by jjh on 2024/1/4.
//
//
#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int>&v,int left,int mid,int right)
{
    vector<int>c;
    c.resize(right-left+1);
    int i = left, j = mid + 1,k = 0;
    while(i<=mid&&j<=right)
    {
        if(v[i]<=v[j])c[k++] = v[i++];
        else c[k++] = v[j++];
    }
    while(i<=mid)c[k++] = v[i++];
    while(j<=right)c[k++] = v[j++];
    //拷贝回原数组
    for(int p = left,q = 0; p<=right;p++,q++)
        v[p] = c[q];
}
void MergeSort(vector<int>&v,int left,int right)
{
    if(left<right)
    {
        int mid = (left + right) / 2;
        MergeSort(v,left,mid);
        MergeSort(v,mid+1,right);
        Merge(v,left,mid,right);
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    MergeSort(data,0,data.size()-1);
    for(int d : data)cout<<d<<" ";
    return 0;
}