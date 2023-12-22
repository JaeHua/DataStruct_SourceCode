//
// Created by 姜杰铧 on 2023/10/18.
//
#include<iostream>
#include <queue>
using namespace std;
const int N = 50;
int mapp[N][N];//存储迷宫地图
int dirx[4] = {0,1,-1,0};
int diry[4] = {1,0,0,-1};
int n,m;
struct Box  //方块类型
{
    int col,row;    //行列号
    Box*pre;    //前驱指针
    Box(){}
    Box(int i,int j)
    {
        row = i;
        col = j;
        pre = nullptr;
    }
};
void output(Box*q)
{
    if(q == nullptr)
        return;
    output(q->pre);
    cout<<"["<<q->row<<","<<q->col<<"]"<<" ";
}
bool BFS(int sx,int sy,int dx,int dy)
{
    queue<Box*>q;
    Box*b1;
    Box*b = new Box(sx,sy);//创建入口对象
    q.push(b);
    mapp[sx][sy] = -1;//标记
    while(!q.empty())
    {
        b = q.front();
        if(b->row == dx && b->col == dy)
        {
            output(b);

            return true;
        }
        q.pop();
        for(int i = 0; i < 4; i ++)
        {
            int nx = b->row + dirx[i];
            int ny = b->col + diry[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&mapp[nx][ny] == 0)
            {
                b1 = new Box(nx,ny);
                b1->pre = b;
                q.push(b1);
                mapp[nx][ny] = -1;//标记
            }
        }
    }
    return false;
}
int main()
{
    cout<<"Enter the row & col of the map :"<<endl;
    cin>>n>>m;
    cout<<"Enter the map matrix:"<<endl;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m; j++)
            cin>>mapp[i][j];
    cout<<"Enter the start point and the end point:"<<endl;
    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    BFS(sx,sy,dx,dy);



    return 0;
}