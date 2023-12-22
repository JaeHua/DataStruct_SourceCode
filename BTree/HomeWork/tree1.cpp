//
// Created by jjh on 2023/11/23.
//
#include <iostream>
#include <fstream>
using namespace std;
int fa[10005];
int len(int x)
{
    int cnt  = 0;
    while(x != fa[x])
    {
        cnt++;
        x = fa[x];
    }
    return cnt;
}
int solve(int x,int y)
{
    if(x == y)return x;
    if(fa[x] == fa[y])return fa[x];
    int c1 = len(x);
    int c2 = len(y);
    int tmp = c1 -  c2;
    if(tmp > 0)
    {
        int t = x;
        while(t!=fa[t])
        {
            if(t == y)return y;
            t = fa[t];
        }
        for(int i = 1; i <= tmp ;i++)
            x = fa[x];
    }
    else
    {
        int t = y;
        while(t!=fa[t])
        {
            if(t == x)return x;
            t = fa[t];
        }
        for(int i = 1; i <= -tmp ;i++)
            y = fa[y];
    }
    while(fa[x]!=fa[y])
    {
        x = fa[x];
        y = fa[y];
    }
    return fa[x];

}
int main()
{
    int n;
    ifstream ifs;
    ifs.open("in.txt");
    ifs>>n;
    for(int i = 1; i <= n;i++)fa[i] = i;
    for(int i = 1; i < n;i++)
    {
        int e,v;
        ifs>>e>>v;
        fa[v] = e;
    }
    int x,y;
    ifs>>x>>y;
    cout<<solve(x,y)<<endl;
    ifs.close();
    return 0;
}

