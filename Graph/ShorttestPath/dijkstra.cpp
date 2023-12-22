#include <iostream>
#define Max 503
#define INF 0xcffffff

using namespace std;

typedef struct AMGraph {							//定义图
    int vex, arc;
    int arcs[Max][Max];								//邻接矩阵
};

int dis[Max], path[Max];							//dis保存最短路径总权值、path通过保存路径的前驱结点来保存路径
bool book[Max];										//已找到最短路集合
int n,m;
void Dijkstra(AMGraph &G)							//迪杰斯特拉算法
{
    for (int i = 1; i <= G.vex; i++)
    {
        dis[i] = G.arcs[n][i];						//初始化dis数组
        path[i] = dis[i] < INF ? n : -1;			//初始化路径数组
    }
    book[1] = true;
    dis[1] = 0;										//起点初始化
    for (int i = 2; i <= G.vex; i++)				//遍历G.vex-1次
    {
        int mins = INF, u = 1;
        for (int j = 1; j <= G.vex; j++)			//找到当前没加入集合的最短路的后驱点
        {
            if (!book[j] && mins > dis[j]) {
                mins = dis[j];
                u = j;
            }
        }
        book[u] = true;								//将该点加入集合
        for (int j = 1; j <= G.vex; j++)			//遍历所有其他点对其最短路进行更新（松弛操作）
        {
            if (!book[j] && dis[j] > dis[u] + G.arcs[u][j]) {
                dis[j] = dis[u] + G.arcs[u][j];		//更新最短路径值
                path[j] = u;						//修改j的前驱为u
            }
        }
    }
}

void find(int x)									//递归输出最短路径
{
    if (path[x] == n) {
        cout << n;
    }
    else {
        find(path[x]);
    }
    cout << " -> " << x;
    return;
}

void putin(AMGraph &G)								//输入图
{
    cin >> G.vex >> G.arc;
    cin>>n>>m;
    for (int i = 1; i <= G.vex; i++)				//初始化邻接矩阵
        for (int j = 1; j <= G.vex; j++)
            G.arcs[i][j] = INF;

    for (int i = 1; i <= G.arc; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.arcs[u][v] = w;
    }
}

void putout(AMGraph &G)								//输出
{
    //cout << "起点 v1 到各点的最短路程为: \n";
    for (int i = 1; i < G.vex; i++)
    {
        cout << dis[i] << " ";
    }
    cout << dis[G.vex] << endl;
    for (int i = 2; i <= G.vex; i++)
    {
        cout << "起点 v1 到 v" << i << " 的路径为： ";
        find(i);
        cout << endl;
    }
}

int main()
{
    AMGraph G;
    putin(G);
    Dijkstra(G);
    putout(G);
//    cout<<dis[m]<<endl;
    return 0;
}
/*
7 12 1 7
1 2 4
1 3 6
1 4 6
2 5 7
2 3 1
3 5 6
3 6 4
4 3 2
4 6 5
5 7 6
6 5 1
6 7 8
*/
