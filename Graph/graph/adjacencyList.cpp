//
// Created by jjh on 2023/12/6.
//

#include "adjacencyList.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
void AdjGraph::CreatedAdjGraph(int a[][MAXV], int n, int e) {
    ArcNode*p;
    this->n = n;this->e = e;//置顶点数和边数
    for(int i = 0; i < n;i++)
        for(int j = n-1;j>=0;j--)//头插倒着
            if(a[i][j]!=0&&a[i][j]!=0x3f3f3f3f)
            {
                p = new ArcNode();
                p->adjvex = j;
                p->weight = a[i][j];
                p->nextarc = adjlist[i].firstarc;
                adjlist[i].firstarc = p;
            }
}

void AdjGraph::DispAdjGraph() {
    ArcNode*p;
    for(int i = 0; i < n;i++) {
        printf("[%d]", i);
        p = adjlist[i].firstarc;
        if(p!= nullptr)printf("->");
        while (p!= nullptr)
        {
            printf(" (%d,%d)",p->adjvex,p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
}

vector<int> AdjGraph::Degree(AdjGraph &G, int v) {
    vector<int>ans = {0,0};
    ArcNode* p = G.adjlist[v].firstarc;
    while (p!= nullptr)
    {
        ans[0]++;
        p = p->nextarc;
    }
    for(int i = 0; i < G.n;i++)
    {
        p = G.adjlist[i].firstarc;
        while(p!= nullptr) {
            if (p->adjvex == v) {
                ans[1]++;
                break;//一个单链表只有一个最多
            }
            p = p->nextarc;
        }
    }
    return ans;
}
int vis[MAXV];
//无回溯版
void AdjGraph::DFS(AdjGraph &G, int v) {
    cout<<v<<" ";
    vis[v] = 1;
    ArcNode*p = G.adjlist[v].firstarc;
    while (p!= nullptr)
    {
        int w = p->adjvex;
        if(!vis[w])DFS(G,w);
        p = p->nextarc;
    }
}

void AdjGraph::BFS(AdjGraph &G, int v) {
    int vi[MAXV];
    memset(vi,0,sizeof(vi));
    queue<int>q;
    cout<<v<<" ";
    q.push(v);
    while (!q.empty())
    {
        int u = q.front();q.pop();
        ArcNode*p = G.adjlist[u].firstarc;
        while (p!= nullptr)
        {
            if(!vi[p->adjvex])
            {
                cout<<p->adjvex<<" ";
                vi[p->adjvex] = 1;
                q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}
int v[MAXV];
void AdjGraph::FindPath1(AdjGraph &G, int u, int vv, vector<int> path) {
    v[u] = 1;
    path.push_back(u);
    if(u == vv)
    {
        for (int i = 0; i < path.size(); ++i) {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    ArcNode*p = G.adjlist[u].firstarc;
    while (p!= nullptr)
    {
        int w = p->adjvex;
        if(!v[w])
            FindPath1(G,w,vv,path);
        p = p->nextarc;
    }
}

void AdjGraph::FindPath(AdjGraph &G, int u, int v) {
    vector<int>path;
    FindPath1(G,u,v,path);
}
void AdjGraph::TopSort(AdjGraph &G) {
    stack<int>st;
    int ind[MAXV];//记录每个顶点的入度
    memset(ind,0,sizeof (ind));
    ArcNode*p;
    for(int i = 0; i < G.n;i++) //求所有顶点的入度
    {
        p = G.adjlist[i].firstarc;
        while(p!= nullptr)
        {
            int w = p->adjvex;
            ind[w]++;
            p = p->nextarc;
        }
    }
    for(int i = 0; i < G.n;i++)
        if(ind[i]==0)
            st.push(i);
    while(!st.empty())
    {
        int i = st.top();st.pop();
        printf("%d",i);
        p = G.adjlist[i].firstarc;
        while (p!= nullptr)
        {
            int w = p->adjvex;
            ind[w]--;
            if(ind[w]==0)   //顶点w的入度减1
                st.push(w);
            p = p->nextarc;
        }
    }
}
