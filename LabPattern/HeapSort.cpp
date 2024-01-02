//
// Created by jjh on 2024/1/2.
//
#include <iostream>
using namespace std;
int tr[1005];
int n;
void shiftdown(int tr[],int low,int high)
{
    int i = low;
    int j = 2*i+1;
    int tmp = tr[i];
    while(j<=high)
    {
        if(j<high&&tr[j]<tr[j+1])
            j++;
        if(tmp<tr[j])
        {
            tr[i] = tr[j];
            i = j;j = 2*i+1;
        }else break;
    }
    tr[i] = tmp;
}
void shiftup(int tr[],int j)
{
    int i = (j - 1)/2;
    while(true)
    {
        if(tr[j]>tr[i])
            swap(tr[i],tr[j]);
        if(i==0)break;
        j = i;i = (j-1)/2;
    }
}
void heapsort(int tr[])
{
    for(int i = (n )/2 - 1; i >= 0; i--)
        shiftdown(tr,i,n-1);
    for(int i = n-1;i>0;i--)
    {
        swap(tr[i],tr[0]);
        shiftdown(tr,0,i-1);
    }
}
void push(int e,int tr[])
{
    n++;
    tr[n-1] = e;
    if(n==1)return;
    shiftup(tr,n-1);
}
void pop(int tr[])
{
    if(n==1)n=0;
    else
    {
        tr[0] = tr[n-1];
        n--;
        if(n>1)shiftdown(tr,0,n-1);
    }
}
int main()
{
    while(cin>>tr[n++]){if (cin.get()=='\n')break;}

    heapsort(tr);
    for(int i = 0; i < n; i++)
        cout<<tr[i]<<" ";
    cout<<endl;
    push(9999,tr);
    heapsort(tr);
    for(int i = 0; i < n; i++)
        cout<<tr[i]<<" ";
    cout<<endl;
    pop(tr);
    heapsort(tr);
    for(int i = 0; i < n; i++)
        cout<<tr[i]<<" ";
    cout<<endl;
    return 0;
}