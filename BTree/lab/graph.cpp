#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define maxn 105
struct ArcNode
{
    int adjvex;
    ArcNode* next;
    ArcNode(){next = nullptr;}
    ArcNode(int a):adjvex(a){};
};
int n,m;
int a[maxn][maxn];
vector<ArcNode*>adjlist(maxn);
void init()
{
    ArcNode*p;
    cin>>n>>m;
    //初始化
    for(int i = 0; i < maxn; i++)
        adjlist[i] = nullptr;
    for(int i = 0; i < m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v] = a[v][u] = 1;//无向图
    }
    for(int i = 0; i < n; i++)
    {
       //由于头插法的反向,j是倒着进行
       for(int j = n - 1; j >= 0;j--)
       {
           if(a[i][j])
           {
               p = new ArcNode(j);
               p->next = adjlist[i];
               adjlist[i] = p;
           }
       }
    }
}
void disp()
{
    ArcNode*p;
    for(int i = 0; i < n; i++)
    {
        cout<<i<<" ";
        p = adjlist[i];
        if(p!= nullptr)cout<<"->";
        while(p!= nullptr)
        {
            cout<<p->adjvex<<" ";
            p = p->next;
        }
        cout<<'\n';
    }
}
bool vis[maxn];
void dfs(int x)
{
    ArcNode*p = adjlist[x];
    vis[x] = 1;
    cout<<x<<" ";
    while(p!= nullptr)
    {
        int q = p->adjvex;
        if(!vis[q])dfs(q);
        p = p->next;
    }
}
bool v[maxn];
int xx;
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    v[x] = 1;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        cout<<u<<" ";
        ArcNode*p = adjlist[u];
        while(p!= nullptr)
        {
            int to = p->adjvex;
            if(!v[to]){q.push(to);v[to] = 1;}
            p = p->next;
        }
    }
}
int main()
{
    init();
//    disp();
    dfs(0);
    cout<<'\n';
    cin>>xx;
    v[xx] = 1;
    bfs(0);
    return 0;
}