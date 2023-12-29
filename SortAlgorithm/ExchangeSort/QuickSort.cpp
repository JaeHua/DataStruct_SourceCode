//
// Created by jjh on 2023/12/29.
//

#include <iostream>
#include <vector>
using namespace std;
int Partition(vector<int>&b,int left,int right)
{
    int pivot = b[left];
    while (left<right)
    {
        while (b[right]>=pivot && left < right)right--;
        b[left] = b[right];
        while (b[left]<=pivot && left < right)left++;
        b[right] = b[left];
    b[left] = pivot;
    }
    return left;
}
void QuickSort(vector<int>&v,int left,int right)
{
    if(left<right)
    {
        int mid = Partition(v,left,right);
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