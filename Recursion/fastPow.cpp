     //
// Created by ½ͺ½άξό on 2023/11/8.
//
#include <iostream>
using namespace std;
typedef long long LL;
//LL fastPow(LL x,int n)
//{
//    if(n == 1)
//        return x;
//    else
//    {
//        if(n&1)
//            return x* fastPow(x,n/2)* fastPow(x,n/2);
//        else
//            return fastPow(x,n/2)* fastPow(x,n/2);
//    }
//}
//LL fastPow(LL x, int n) {
//         if(n == 0) return 1;
//         LL res = 1;
//         if(!(n & 1)) {
//             res = fastPow(x, n/2);
//             res *= res;
//         }
//         else {
//             res = x * fastPow(x, n-1);
//         }
//         return res;
//}
LL fastPow(LL x,int n)
     {
    if(n == 1)
        return x;
    LL p = fastPow(x,n/2);
    if(n&1)
        return x*p*p;
    else
        return p*p;
     }
int main()
{
    LL x;
    int n;
    cin>>x>>n;
    cout<<x<<"^"<<n<<"="<<fastPow(x,n)<<endl;
    return 0;
}