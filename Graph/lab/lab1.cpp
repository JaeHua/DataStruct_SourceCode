//
// Created by jjh on 2023/12/24.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10005
struct edge
{
    int id;
    int w;
    int u;
    int v;
}edges[maxn];
int n,m;
int id_;
vector<int> _id;
int fa[maxn];//存放父亲结点
//比较函数
bool comp(edge a, edge b)
{
return a.w<b.w;
}
//初始化
void init()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++)
        cin>>edges[i].id>>edges[i].u>>edges[i].v>>edges[i].w;
    //对父亲结点数组进行初始化
    for(int i = 1;i <= n;i++ )
        fa[i] = i;
    sort(edges, edges + m, comp);
}
int find(int x)
{
 if(x == fa[x])
     return x;
 else return find(fa[x]);
}
int kruskal()
{
    int ans = 0; //记录MST的最小权值和
    int num_edg=0; //边的数目
    for(int i = 0; i < m; i++)
    {
        int fu = find(edges[i].u);
        int fv = find(edges[i].v);
        if(fu!=fv)
        {
            fa[fu] = fv;//合并
            ans += edges[i].w;
            _id.push_back(edges[i].id);
            num_edg++;
            if(num_edg == n-1)break;
        }
    }
    return ans;
}
int main(){
    init();
    cout<<kruskal()<<endl;
    sort(_id.begin(),_id.end());
    for(int i = 0; i < n-1;i++)
        cout<<_id[i]<<" ";
    cout<<endl;
//    for(int i = 0; i < n; i++)
//        if(find(i) == id_)
//            _id.push_back(edges[i].id);
    return 0;
}
/*
6 10
1 0 1 600
2 0 2 100
3 0 3 500
4 1 2 500
5 2 3 500
6 1 4 300
7 2 4 600
8 2 5 400
9 3 5 200
10 4 5 600
 */