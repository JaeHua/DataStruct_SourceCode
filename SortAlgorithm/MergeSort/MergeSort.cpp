//
// Created by jjh on 2023/12/29.
//

#include <iostream>
#include <vector>
using namespace std;
//int tmp[1005];
//void MergesortMine(vector<int>&v,int left, int right) {
//    if (left == right) { return; }
//    int mid = (left + right) / 2;
//    int  i = left, j = mid + 1, k = left;
//    Mergesort(v,left, mid);
//    Mergesort(v,mid + 1, right);
//    while (i <= mid && j <= right) {
//        if (v[i] <= v[j]) {
//            tmp[k] = v[i]; k++; i++;
//        }
//        else {
//            tmp[k] = v[j]; k++; j++;
//        }
//    }
//    while (i <= mid) {
//        tmp[k] = v[i]; k++; i++;
//    }
//    while (j <= right) {
//        tmp[k] = v[j]; k++; j++;
//    }
//    for (int i = left; i <= right; i++) {
//        v[i] = tmp[i];
//    }
//}
void Merge1(vector<int>&v,int low,int mid,int high)
{
    vector<int>v1;
    v1.resize(high-low+1);
    int i = low,j = mid + 1,k=0;
    while (i<=mid&&j<=high)
    {
        if(v[i]<=v[j])v1[k++] = v[i++];
        else v1[k++] = v[j++];
    }
    while(i<=mid)v1[k++] = v[i++];
    while(j<=high)v1[k++] = v[j++];

    for(k = 0,i = low;i<=high;k++,i++)
        v[i] = v1[k];   //复制回原向量
}

void MergeSort(vector<int>&v,int left,int right)
{
    if(left>=right)return;
    int mid = (left+right)/2;
    MergeSort(v,left,mid); //归
    MergeSort(v,mid+1,right);
    Merge1(v,left,mid,right);//并
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
//    MergesortMine(data,0,data.size()-1);
    MergeSort(data,0,data.size()-1);
    for(int d : data)cout<<d<<" ";
    return 0;
}