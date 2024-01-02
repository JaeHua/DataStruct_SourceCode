#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
const int INF = 0x3f3f3f3f;
int edge[MAXN][MAXN], dist[MAXN], closed[MAXN];
bool vis[MAXN];
int n, e;
void init()
{
    cin >> n >> e;
    memset(edge, INF, sizeof(edge));
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge[x][y] = edge[y][x] = w;//无向图
    }
}
void prim(int s)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = edge[s][i];
        closed[i] = s;//初始化全部是指向源点s
    }
    vis[s] = 1;
    for (int i = 1; i < n; i++)//找到n-1个点加入进来
    {
        int minn = INF;
        int k = -1;
        for(int j = 0 ;j < n;j++)
            if (!vis[j] && dist[j] < minn)
            {
                minn = dist[j];
                k = j;
            }
        cout << "边(" << closed[k] << "," << k << ") = " << minn << endl;
        dist[k] = 0;
        vis[k] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dist[j] > edge[k][j])
            {
                dist[j] = edge[k][j];
                closed[j] = k;
            }
        }
    }
}
int main() {
    init();
    prim(0);
    return 0;
}