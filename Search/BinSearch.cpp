//
// Created by jjh on 2023/12/21.
//
//
// Created by jjh on 2023/12/21.
//
#include <iostream>
using namespace std;
int n;
int a[105] = {1,2,3,4,5,6,9,33,40,42};
int BinSearch()
{
    int i = 0; int r = 10;
    int left = 0,right = r-1;
    while (left<=right)
    {
        int mid = left + (right-left)/2;
        if(n == a[mid])return mid;
        else if(n<a[mid])right = mid-1;
        else left = mid + 1;
    }
    return -1;
}
int main(){
    cin>>n;
    if(BinSearch()==-1)printf("%d Not Exists!",n);
    else cout<< n<<" is at "<<BinSearch()<<endl;
    return 0;
}