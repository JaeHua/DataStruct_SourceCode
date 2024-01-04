//
// Created by jjh on 2024/1/4.
//
//
#include <iostream>
#include <vector>
using namespace std;
int getMid(vector<int>&v,int left,int right)
{
    int pivot = v[left];
    while(left<right)
    {
        while(v[right]>=pivot&&left<right)right--;
        v[left] = v[right];
        while(v[left]<=pivot&&left<right)left++;
        v[right] = v[left];
        v[left] = pivot;
    }
    return left;
}
void QuickSort(vector<int>&v,int left,int right)
{
    if(left<right)
    {
        int mid = getMid(v,left,right);
        QuickSort(v,left,mid-1);
        QuickSort(v,mid+1,right);
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    QuickSort(data,0,data.size()-1);
    for(int d : data)cout<<d<<" ";
    return 0;
}