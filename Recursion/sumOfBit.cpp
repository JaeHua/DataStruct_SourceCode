//
// Created by ½ª½Üîü on 2023/11/8.
//
#include <iostream>
using namespace std;
int f(int n)
{
    if(n < 10)
        return n;
    else
        return f(n/10) + n%10;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}