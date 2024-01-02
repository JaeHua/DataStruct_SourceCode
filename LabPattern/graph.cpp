//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>

using namespace std;
const int maxv = 100;
const int maxe = 200;
const int INF = 0x3f3f3f3f;
int head[maxv];
int n,m,cnt;
struct edge
{
    int to;
    int w;
    int nxt;
}edges[maxe];
int a[maxv][maxv];
void add(int u,int v,int w)
{
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
void init()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(int i = 0 ; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]= w;
    }
    for(int i = 0 ; i <n;i++)
    {
        for(int j =n-1;j>=0;j--)
        {
            if(a[i][j])
            {
                add(i,j,a[i][j]);
                add(j,i,a[i][j]);
            }
        }
    }
}
bool vis[maxv];
void dfs(int v)
{
    cout<<v<<" ";
    vis[v] = 1;
    for(int i = head[v];i!=-1;i = edges[i].nxt)
    {
        int u = edges[i].to;
        if (!vis[u]) {
            dfs(u);
        }
    }
}
bool vi[maxv];
void bfs(int v)
{
    queue<int>q;
    q.push(v);
    vi[v] = 1;
    while(!q.empty())
    {
        int u= q.front();q.pop();
        cout<<u<<" ";
        for(int i= head[u];i!=-1;i = edges[i].nxt)
        {
            int p = edges[i].to;
            if(!vi[p]){q.push(p);vi[p]=1;}
        }
    }
}
int main(){

    init();
    dfs(0);
    cout<<endl;
    int f;
    cin>>f;
    vi[f] = 1;
    bfs(0);
    return 0;
}
/*
9 10
0 1 1
0 2 1
1 3 1
1 4 1
1 8 1
2 5 1
2 7 1
3 6 1
5 7 1
6 8 1
3
*/