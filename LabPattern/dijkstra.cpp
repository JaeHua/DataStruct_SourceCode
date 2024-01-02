//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
#define Max 503
#define INF 0xcffffff
int a[Max][Max],dist[Max],path[Max];
bool vis[Max];
int n,m,s,e;
void init()
{
    cin>>n>>m>>s>>e;
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = INF;
    for(int i = 1; i <= m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v] = w;
    }
}
void dijkstra()
{
    for(int i = 1; i <= n; i++)
    {
        dist[i] = a[s][i];
        path[i] = dist[i] < INF ? s : -1;
    }
    vis[s] = 1;
    dist[s] = 0;
    for(int i = 2;  i <= n;i++)//切记n-1次
    {
        int minn = INF, k = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j]&&minn>dist[j])
            {
                minn = dist[j];
                k = j;
            }
        }
        if(k==-1)break;
        vis[k] = 1;

        for(int j = 1; j <= n; j++)
        {
            if(!vis[j]&&dist[j]>dist[k] + a[k][j])
            {
                dist[j] = dist[k] + a[k][j];
                path[j] = k;
            }
        }
    }
}
void find(int x)									//递归输出最短路径
{
    if (path[x] == s) {
        cout << s;
    }
    else {
        find(path[x]);
    }
    cout << " -> " << x;
    return;
}
int main(){
    init();
    dijkstra();

    for(int i = 1; i <= n; i++)
        cout<<"dist["<<i<<"]="<<dist[i]<<"\t ";
    cout<<endl;
    for(int i = 1; i <= n; i++)
        cout<<"path["<<i<<"]="<<path[i]<<"\t ";
    cout<<endl;
    find(e);
    return 0;
}