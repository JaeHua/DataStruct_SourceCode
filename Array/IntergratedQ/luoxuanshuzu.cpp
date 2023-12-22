//
// Created by ������ on 2023/11/1.
//
/**
 * ����������

��дһ�����򣬶����������������n(n������10)����������ʾn������ʽ���ַ�����n=3 Ҫ��ʾ�ķ���Ϊ

1 2 3
8 9 4
7 6 5
��������ʽ��

����һ����n
�������ʽ��

����n���������־��������Կո����*/
#include <iostream>
#include <vector>
using namespace std;
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1};
int cnt = 0;
void solve(vector<vector<int>>&f,int n)
{
    int x = 0;
    int y = 0;
    int step = 1;
    while(step <= n*n)
    {
        while(y<n&&!f[x][y])
        {
            f[x][y] = step++;
            y++;
        }
        y--;
        x++;
        while(x<n&&!f[x][y])
        {
            f[x][y] = step++;
            x++;
        }
        x--;
        y--;
        while(y>=0&&!f[x][y])
        {
            f[x][y] = step++;
            y--;
        }
        y++;
        x--;
        while(x>=0&&!f[x][y])
        {
            f[x][y] = step++;
            x--;
        }
        x++;
        y++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    solve(f,n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n;j++)
            cout<<f[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}