//
// Created by ½ª½Üîü on 2023/11/8.
//
#include <iostream>
using namespace std;
int f(int n)
{
    if(n == 1|| n==2)
        return 1;
    int a = 1,b = 1,c;
    for(int i = 3; i <= n;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main(){

    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}