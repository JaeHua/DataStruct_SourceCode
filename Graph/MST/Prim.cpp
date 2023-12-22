//
// Created by jjh on 2023/12/6.
//
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
const int INF = 0x3f3f3f3f;
int edge[MAXN][MAXN],dist[MAXN],closed[MAXN];
bool vis[MAXN];
int n,e;
void Prim(int v)
{
    for(int i = 0; i < n;i++) {
        dist[i] = edge[v][i];//以v为起点
        closed[i] = v;
      }
    vis[v] = 1;
    for(int i = 1; i < n;i++)//n-1次
    {
        int minn = INF;
        int k = -1;//记录最近的顶点
        for(int j = 0; j <n;j++)//在(V-U)中找到离U最近的顶点k
            if(!vis[j]&&dist[j]!=0&&dist[j]<minn)
            {
                minn = dist[j];
                k = j;
            }
        cout<<" 边("<<closed[k]<<","<<k<<"),权为"<<minn<<endl;
        dist[k] = 0;
        vis[k] = 1;
        for(int j = 0; j < n; j++)
            if(!vis[j]&&dist[j]!=0&&edge[k][j]<dist[j])
            {
                dist[j] = edge[k][j];
                closed[j] = k;
            }
    }
}
int main(){
    memset(edge,INF,sizeof(edge));
    cin>>n>>e;
    for(int i = 0; i < e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edge[x][y] = edge[y][x] = w;
    }
    Prim(0);
    return 0;
}
/*
6 10
 0 1 6
 0 3 5
 0 2 1
 1 2 5
 1 4 3
 2 3 5
 2 4 6
 2 5 4
 3 5 2
 4 5 6
 */