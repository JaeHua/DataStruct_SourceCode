//
// Created by jjh on 2023/11/22.
//
#include <iostream>
using namespace std;
const int MAXV = 100; //最多顶点数
const int INF = 0x3f3f3f3f;
class MatGraph
{
public:
    int edges[MAXV][MAXV];
    int n,e;//顶点数与边数
    string vexs[MAXV]; //存放顶点信息
    void CreateMatGraph(int a[][MAXV],int n,int e)
    {
    this->n = n;
    this->e = e;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++)
            this->edges[i][j] = a[i][j];
    }
    void DispMatGraph()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(edges[i][j] == INF)
                    printf("%4s","~");
                else
                    printf("%4d",edges[i][j]);
            }
            cout<<endl;
        }
    }
};

int main() {
    int adjacencyMatrix[MAXV][MAXV] = {
            { 0, 2, INF, 1 },
            { 2, 0, 4, INF },
            { INF, 4, 0, 5 },
            { 1, INF, 5, 0 }
    };
    int numVertices = 4;
    int numEdges = 6;

    MatGraph graph;
    graph.CreateMatGraph(adjacencyMatrix, numVertices, numEdges);

    cout << "Adjacency Matrix Representation:" << endl;
    graph.DispMatGraph();

    return 0;
}