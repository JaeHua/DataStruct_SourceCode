//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
int a[105];
int getMid(int a[], int left, int right)
{
    int pivot = a[left];
    while (left <  right)
    {
        while (left < right && a[right] >= pivot)right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)left++;
        a[right] = a[left];

        a[left] = pivot;
    }
    return left;
}
void quick_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = getMid(a, left, right);
        quick_sort(a, left, mid-1);
        quick_sort(a, mid+1,right);

    }
}
int main() {
    int i = 0,value = 0;
    while (cin >> a[i++])
    {

        if (cin.get() == '\n')break;
    }

//	sort(a,a+i);
    quick_sort(a, 0, i - 1);
    for (int k = 0; k < i; k++)
        cout << a[k] << " ";

    return 0;
}