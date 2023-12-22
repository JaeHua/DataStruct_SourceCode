//
// Created by 姜杰铧 on 2023/10/19.
//
/**
 * 有一个整数数组a,设计一个算法，将所有偶数位的元素移动到所有奇数位元素的前面，要求他们的相对次序不变
 * */
#include <iostream>
#include <queue>
int a[1005];
using namespace std;
void solve(int arr[],int n)
{
    queue<int>odd;
    queue<int>even;
    for(int i = 0 ; i < n;i++)
        if(a[i]&1)
            odd.push(a[i]);
        else
            even.push(a[i]);

    while(!odd.empty())
    {
        even.push(odd.front());
        odd.pop();
    }
    while(!even.empty()) { cout << even.front() << " ";even.pop(); }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Please enter the length of the array and the element of the array:"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<"After the alogrimth:"<<endl;
    solve(a,n);
    return 0;
}
