//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
//deg[i]记录i点的入度
int edge[105][105],deg[105];
int n;
//建图
void init(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        int t;
        while(cin>>t&&t){
            //有向图建图单向边
            edge[i][t] = 1;
            deg[t]++;
        }
    }
}
//拓扑排序模板
void topoSort(){
    queue<int>q;
    for(int i = 1;i<=n;i++)
        if(deg[i]==0){
            cout<<i<<" ";
            q.push(i);
        }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1;v<=n;v++)
            if(edge[u][v]){
                deg[v]--;
                if(deg[v]==0){
                    cout<<v<<" ";
                    q.push(v);
                }
            }
    }
}
int main(){
    init();
    topoSort();
    return 0;
}