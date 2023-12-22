//
// Created by jjh on 2023/12/21.
//
#include <iostream>
#include <vector>

#define Max 503
#define INF 0xcffffff

using namespace std;

typedef struct AMGraph {							//定义图
    int vex, arc;
    int arcs[Max][Max];								//邻接矩阵
};

int  path[Max][Max];							//dis保存最短路径总权值、path通过保存路径的前驱结点来保存路径
void putin(AMGraph &G)								//输入图
{
    cin >> G.vex >> G.arc;
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
void dispath(int a[][Max],int n)
{
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n;j++)
        {
            if(a[i][j]!=INF && i!=j)
            {
                vector<int>apath;
                printf("顶点%d到顶点%d的最短路径长度:%d 路径:",i,j,a[i][j]);
                apath.push_back(j);
                int pre = path[i][j];
                while (pre!=i)
                {
                    apath.push_back(pre);
                    pre = path[i][pre];

                }
                cout<<i;
                for (int k = apath.size()-1; k >=0 ; --k) {
                    printf("->%d",apath[k]);

                }
                printf("\n")    ;
            }
        }
}
void floyed(AMGraph &G)
{

    int a[Max][Max];
    for(int i = 1;i <= G.vex;i++)
        for(int j = 1; j <= G.vex;j++)
        {
            a[i][j] = G.arcs[i][j];
            if(i!=j && G.arcs[i][j]<INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    for(int k =1; k <= G.vex;k++)
        for(int i = 1; i <= G.vex;i++)
            for(int j = 1;j <= G.vex;j++)
                if(G.arcs[i][j] > G.arcs[i][k] + G.arcs[k][j])
                {
                    G.arcs[i][j] = G.arcs[i][k] + G.arcs[k][j];
                    path[i][j] = path[k][j];
                }
    dispath(a,G.vex);
}

int main() {
    AMGraph G;
    putin(G);
    floyed(G);

    return 0;
}
/*
7 12
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
6 7 8*/