//
// Created by 姜杰铧 on 2023/11/10.
//
#include <iostream>
#include <chrono>
using namespace std;
typedef long long LL;
//递归
LL solve(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return solve(n-1) + solve(n-2);
}
//动态规划
LL dp[50];
LL solve1(int n)
{
   dp[1] = dp[2] = 1;
    for(int i = 3; i <= n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    auto start = chrono::high_resolution_clock::now();
    cout<<solve(n)<<endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " seconds" << endl;
    return 0;
}