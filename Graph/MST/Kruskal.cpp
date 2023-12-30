//
// Created by jjh on 2023/12/20.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int fa[maxn];//存放父亲结点
struct Edge
{
    int u;
    int v;
    int w;
    int id;
}edges[maxn];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
//初始化
void init(int n)
{
    //对父亲结点数组进行初始化
    for(int i = 0;i < n;i++ )
        fa[i] = i;
}
int find(int x)
{
    if(x == fa[x])
        return x;
    return find(fa[x]);
}
int kruskal(int n,int m)
{
    int ans = 0;//记录MST的权值
    int num_edg=0;//边的数目
    for(int i = 0; i < m; i++)
    {
        int fu = find(edges[i].u);
        int fv = find(edges[i].v);
        if(fu!=fv)
        {
            fa[fu] = fv;//合并
            ans += edges[i].w;
            num_edg++;
            if(num_edg == n-1)break;
        }
    }
    if(num_edg!=n-1)return -1; //无MST
    else return ans;
}
int main() {
    int n, m;
//    cout << "Enter the number of nodes (n): ";
    cin >> n;
//    cout << "Enter the number of edges (m): ";
    cin >> m;

    init(n);

//    cout << "Enter the edges in the format (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + m, cmp);

    int result = kruskal(n, m);
    if (result == -1) {
        cout << "No MST exists." << endl;
    } else {
        cout << result << endl;
    }

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
/*
result = 15
*/