//
// Created by jjh on 2023/12/6.
//

#ifndef CPP_ADJACENCYLIST_H
#define CPP_ADJACENCYLIST_H
#include <string>
#include <vector>
using namespace std;
#define MAXV 1005
#define INF 0x3f3f3f3f
struct ArcNode//边结点类型
{
    int adjvex;//邻接点
    int weight;//权值
    ArcNode*nextarc;//指向下一条边结点
};
struct HNode//头结点类型
{
    std::string info;
    ArcNode*firstarc;//指向第一条边的边结点
};
class AdjGraph {
public:
    HNode adjlist[MAXV];
    int n,e;//顶点数和边数
    AdjGraph()
    {
        for(int i = 0; i < MAXV;i++)
            adjlist[i].firstarc = nullptr;
    }
    ~AdjGraph()
    {
        ArcNode*pre,*p;
        for(int i = 0; i < n;i++)
        {
            pre = adjlist[i].firstarc;
            if(pre!= nullptr)
            {
                p = pre->nextarc;
                while(p!= nullptr)
                {
                    delete pre;
                    pre = p;
                    p = p->nextarc;
                }
                delete pre;
            }
        }
    }
    void CreatedAdjGraph(int a[][MAXV],int n,int e);
    void DispAdjGraph();
    vector<int>Degree(AdjGraph&G,int v);//有向图出度与入度ans[0]记录出度
    void DFS(AdjGraph&G,int v);
    void BFS(AdjGraph&G,int v);
    void FindPath1(AdjGraph&G,int u,int v);
    void FindPath(AdjGraph&G,int u,int v);
    void TopSort(AdjGraph&G);//拓扑排序
};


#endif //CPP_ADJACENCYLIST_H
