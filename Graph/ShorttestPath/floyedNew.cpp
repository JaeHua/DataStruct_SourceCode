//
// Created by jjh on 2023/12/30.
//
#include<bits/stdc++.h>
using namespace std;
#define Max 503
#define INF 0xcffffff
int a[Max][Max];
int n,m;
int path[Max][Max];
void init()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = INF;
    for(int i = 1; i <= m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v] = w;
    }
}
void disp()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j]!=INF&&i!=j)
            {
                vector<int>apath;
                printf("顶点%d到顶点%d的最短路径长度:%d 路径:",i,j,a[i][j]);

                apath.push_back(j);
                int pre = path[i][j];
                while(pre!=i)
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
void floyed()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i!=j&&a[i][j]<INF)
                path[i][j] = i;
            else path[i][j] = -1;
        }
    for(int k = 1; k <= n; k++)
        for(int i =1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = k;
                }
            }
    disp();
}
int main()
{
    init();
    floyed();

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
6 7 8
*/