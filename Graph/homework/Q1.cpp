//
// Created by jjh on 2023/12/22.
//
/*
 * 给定n个村庄，如果村庄i与j之间有路联通，则将i，j之间连上边，边的权值Wij表示这条路的长度。

现在选定一个村庄建医院，设计一个算法求出该医院应该建在哪个村庄，才能使距离医院最远的村庄到医院的路程达到最短。
【输入形式】

第一行输入村庄个数N（3<N<10）

之后输入邻接矩阵，如果i，j之间没有直接的通路，Wij为0

W11，W12，...W1n*/
#include <iostream>
using namespace std;
#define INF  0x3f3f3f3f
#define maxn 105
int n;//村庄个数
int f[maxn];
int d[maxn][maxn];
void init()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            int w;cin>>w;
            if(w == 0)w = INF;
            d[i][j] = d[j][i] = w;
        }
    for(int i = 1; i <= n; i++)d[i][i] = 0;
}
void floyed()
{
    for(int k =1; k <= n;k++)
        for(int i = 1; i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];

                }
}
int MinMax() {
    int minMaxRow;
    int Maxmin = INF;
    for(int i = 1; i <= n; i++)
    {
        int minn = d[i][1];
        for(int j = 1; j <= n;j++)
            if(d[i][j]>minn)
                minn = d[i][j];
        if(Maxmin > minn)
        {
            Maxmin = minn;
            minMaxRow = i;
        }
    }
    return minMaxRow;
}
int main(){
    init();
    floyed();
    cout<<MinMax()<<endl;

    return 0;
}