
//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
int fa[1005];
int n,m;
struct edge{
    int u;
    int v;
    int w;
}edges[1005];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
void init()
{
    cin>>n>>m;
    for(int i = 0; i < n;i++)
        fa[i] = i;
    for(int i = 0; i < m;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges,edges+m,cmp);
}

int find(int x)
{
    if(x==fa[x])
        return x;
    return find(fa[x]);
}
int kruskal()
{
    int ans  = 0;//
    int cnt = 0;//
    for(int i = 0; i < m;i++)
    {
        int fu = find(edges[i].u);
        int fv = find(edges[i].v);
        if(fu!=fv)
        {
            fa[fu] = fv;
            ans += edges[i].w;
            cnt++;
            if(cnt == n - 1)break;
        }
    }

    if(cnt == n-1)return ans;
    else return -1;
}
int main(){
    init();
    int res = kruskal();
    if(res == -1)
        cout<<"MST do not exist!"<<endl;
    else cout<<"w = "<<res<<endl;
    return 0;
}
/*
6 10
0 1 6
0 2 1
0 3 5
1 2 5
1 4 3
2 4 6
2 5 4
3 5 2
4 5 6
2 3 5
*/