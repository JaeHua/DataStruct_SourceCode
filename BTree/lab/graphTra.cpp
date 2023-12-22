#include<iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int n, m;
const int maxn = 1e4;
const int maxm = 1e5;
int cnt;
struct edge {
    int to;   // 指向的点
    int next; // 上一条边编号
} edges[maxm];

int first[maxn]; // 以i点起，最多存储到的编号

void add(int u, int v) {
    edges[cnt].to = v;           // 读入指向边
    edges[cnt].next = -1;       // 将next初始化为-1

    if (first[u] == -1) {
        first[u] = cnt;         // 如果该顶点没有边，直接将当前边作为第一条边
    } else {
        int last = first[u];    // 找到该顶点的最后一条边
        while (edges[last].next != -1) {
            last = edges[last].next;
        }
        edges[last].next = cnt;  // 将当前边连接到最后一条边的后面
    }

    cnt++;                      // 更新边的计数

}

void visit(int u) {
    for (int i = first[u]; i != -1; i = edges[i].next) {
        printf("%d--%d\n", u, edges[i].to);
    }
}

bool vis[maxn]; // 标记已访问的顶点

void dfs(int x) {

    vis[x] = true;
    cout<<x<<" ";
    for (int i = first[x]; i != -1; i = edges[i].next) {
        int u = edges[i].to;
        if (!vis[u]) {
            dfs(u);
        }
    }
}
bool v[maxm];
void bfs(int x)
{
    queue<int>qu;
    v[x] = 1;
    qu.push(x);
    while(!qu.empty())
    {
        int u = qu.front();qu.pop();
        cout<<u<<" ";
        for(int i = first[u]; i!=-1;i = edges[i].next)
        {
            int vi = edges[i].to;
            if(!v[vi]) { qu.push(vi); v[vi] = true;}
        }
    }
}
void del(int u) {
    // 删除以u为起始节点的所有边
    int cur = first[u];
    while (cur != -1) {
        int nextEdge = edges[cur].next;
        edges[cur].to = -1;   // 将to字段置为-1，表示删除该边
        edges[cur].next = -1; // 将next字段置为-1，断开该边的链接

        cur = nextEdge;
    }

    // 删除指向u的边
    for (int i = 0; i < n; i++) {
        if (i == u) {
            continue;
        }
        cur = first[i];
        while (cur != -1) {
            if (edges[cur].to == u) {

                if (first[i] == cur) {
                    first[i] = edges[cur].next; // 更新节点i的出边
                } else {
                    int prev = first[i];
                    while (edges[prev].next != cur) {
                        prev = edges[prev].next;
                    }
                    edges[prev].next = edges[cur].next; // 更新节点i的出边
                }
                edges[cur].to = -1;   // 将表示删除该边
                edges[cur].next = -1; // 断开该边的链接
            }
            cur = edges[cur].next;
        }
    }
}
int main() {

    cin >> n >> m;
    memset(first, -1, sizeof(first));

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

//    for (int i = 0; i < n; i++) {
//        visit(i);
//    }

    dfs(0);
    cout << '\n';
    int xx;
    cin>>xx;
//    del(xx);
    v[xx] = 1;
//    for(int i = 0; i < 9;i++)
//        cout<<"first["<<i<<"]="<<first[i]<<endl;
    bfs(0);
    cout<<'\n';
    return 0;
}
/*
9 10
0 1
0 2
1 3
1 4
1 8
2 5
2 7
3 6
5 7
6 8*/


