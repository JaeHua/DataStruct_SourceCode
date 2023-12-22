//
// Created by jjh on 2023/11/12.
//
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>f(m,vector<int>(n));
    vector<int>row(m);
    vector<int>col(n);
    for(int i = 0; i < m;i++)
        for(int j = 0; j < n;j++) {
            cin >> f[i][j];
            row[i] += f[i][j];
        }
    for(int j = 0; j < n;j++)
        for(int i = 0; i < m;i++)
            col[j] += f[i][j];
    int ans = 0;
    for(int i = 0; i < m;i++)
        for(int j = 0; j < n;j++)
            if(row[i] == col[j])
                ans++;
    cout<<ans<<endl;
    return 0;
}