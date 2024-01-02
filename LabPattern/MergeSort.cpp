//
// Created by jjh on 2024/1/2.
//
#include<iostream>
#include<vector>
using namespace std;
int n;
int a[1005];
void merge(int a[],int left,int mid,int right)
{
    vector<int>v;
    v.resize(right-left+1);
    int k = 0,i = left,j = mid + 1;
    //这里要取等于号
    while(i<=mid&&j<=right)
    {
        if(a[i] <= a[j])v[k++] = a[i++];
        else v[k++] = a[j++];
    }
    while(i<=mid)v[k++] = a[i++];
    while(j<=right)v[k++] = a[j++];

    for(int k = 0, i = left; i <= right;i++,k++)
        a[i] = v[k];

}
void msort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = (l + r)/2;
        msort(a,l,mid);
        msort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    while(cin>>a[n++])
    {
        if(cin.get() =='\n')break;
    }
    msort(a,0,n-1);
    for(int i = 0;  i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}