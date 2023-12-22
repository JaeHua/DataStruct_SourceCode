//
// Created by jjh on 2023/12/6.
//
#include "adjacencyList.cpp"
#include <cstring>
#include <iostream>
int main() {
    int a[105][1005];
    memset(a,0x3f3f3f3f,sizeof(a));
    int n,e;
    cin>>n>>e;
    for(int i = 0; i < n;i++)a[i][i] = 0;
    for(int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y>>a[x][y];
    }
    AdjGraph graph;
    graph.CreatedAdjGraph(a, n, e);
    graph.DispAdjGraph();

    int vertex = 2;
    std::vector<int> degree = graph.Degree(graph, vertex);
    std::cout << "Degree of vertex " << vertex << ": " << degree[0] << std::endl;
    std::cout << "Degree of adjacent vertices to vertex " << vertex << ": " << degree[1] << std::endl;
    cout<<"the dfs path :";
    graph.DFS(graph,0);
    cout<<"\n";
    cout<<"the bfs path :";
    graph.BFS(graph,0);
    cout<<"\n";
    cout<<"0 --> 3 path :";
    graph.FindPath(graph,0,3);
    cout<<"Topsort: ";
    graph.TopSort(graph);
    return 0;
}
/*
6 7
0 1 3
0 2 4
1 5 5
2 5 6
2 3 7
2 4 8
4 3 9
 */