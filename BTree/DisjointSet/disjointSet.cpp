//
// Created by jjh on 2023/11/22.
//
#include <iostream>
using namespace std;
const int MAXN = 1005;
int fa[MAXN];
//优化数组
int rnk[MAXN];
int n,m;
void init()
{
    for(int i  = 1; i <= n; i++) {
        fa[i] = i;
        rnk[i] = 0;
    }
}
int Find(int x)
{
    if(x!=fa[x])
        fa[x] = Find(fa[x]);
    return fa[x];
}
void Union(int x,int y)
{
    int rx = Find(x);
    int ry = Find(y);
    if(rx == ry)
        return;
    if(rnk[rx]<rnk[ry])
        fa[rx] =ry;
    else
    {
        if(rnk[rx] == rnk[ry])
            rnk[rx]++;
        fa[ry] =rx;
    }
}
int main() {
    n = 5; // number of elements
    m = 4; // number of union operations

    init(); // initialize the disjoint set

    // Perform union operations
    Union(1, 2);
    Union(3, 4);
    Union(5, 3);
    Union(4, 5);

    // Find representative for each element and print the result
    for (int i = 1; i <= n; i++) {
        cout << "Element " << i << " belongs to set with representative: " << Find(i) << endl;
    }

    return 0;
}