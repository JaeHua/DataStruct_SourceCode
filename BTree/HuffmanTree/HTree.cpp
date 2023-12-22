//
// Created by jjh on 2023/11/22.
//

#include <iostream>
#include <queue>
#include<algorithm>
using namespace  std;
//结点类型
struct HTNode
{
    char data;//结点值
    double weight; //权值
    int parent;//双亲结点
    int lchild;//左孩子结点
    int rchild;//右孩子结点
    bool flag;//标识是双亲的左孩子(true)结点还是右孩子结点，便于编码
    HTNode()
    {
        parent = -1;
        lchild = rchild = -1;
        flag = true;
    }
    HTNode(char d,double w)
    {
        data = d;
        weight = w;
        parent = lchild = rchild = -1;
        flag = true;
    }
}ht[1005];
//优先队列元素类型
char D[1005];
double W[1005];
int n;
string hcd[1005];
struct HeapNode
{
    double w;//权值
    int i;  //对应哈夫曼树中结点编号
    HeapNode(double w1,int i1):w(w1),i(i1){}
    bool operator <(const HeapNode&s)const
    {
        return w>s.w;//按w越小先出队
    }
};
void CreateHT()
{
    priority_queue<HeapNode>qu;//小根堆
    for(int i = 0; i < n;i++)
    {
        ht[i] = HTNode(D[i],W[i]);//建立叶子结点
        qu.push(HeapNode(W[i],i));
    }
    for(int i = n; i < 2*n - 1;i++)//做n-1次合并
    {
        //最小权值的两个点出队
        HeapNode p1 = qu.top();qu.pop();
        HeapNode p2 = qu.top();qu.pop();
        ht[i] = HTNode();   //新建ht结点
        ht[i].weight = ht[p1.i].weight + ht[p2.i].weight;
        ht[p1.i].parent = i;//设置双亲
        ht[i].lchild = p1.i;
        ht[p1.i].flag = true;//表明左孩子
        ht[p2.i].parent = i;
        ht[i].rchild = p2.i;
        ht[p2.i].flag = false;
        qu.push(HeapNode(ht[i].weight,i));
    }
}
//根据哈夫曼树进行的编码
void CreateHCode()
{
    for(int i = 0; i < n; i++)
    {
        string code = "";
        int j = i;
        while (ht[j].parent!=-1)
        {
            if(ht[j].flag)
                code += "0";
            else
                code +="1";
            j = ht[j].parent;
        }
        //记得逆置
        reverse(code.begin(),code.end());
        hcd[i] = code;
    }
}


int main() {
    // Sample input data
    char data[] = { 'A', 'B', 'C', 'D' };
    double weight[] = { 1, 3, 5, 7 };
    int numNodes = sizeof(data) / sizeof(data[0]);

    // Set the global variables
    n = numNodes;
    for (int i = 0; i < n; i++) {
        D[i] = data[i];
        W[i] = weight[i];
    }

    // Create the Huffman tree
    CreateHT();

    // Print the Huffman tree structure
    cout << "Huffman tree structure:" << endl;
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << "Node " << i << ": ";
        if(i<n)
            cout << "Data = " << ht[i].data << ", ";
        cout << "Weight = " << ht[i].weight << ", ";
        cout << "Parent = " << ht[i].parent << ", ";
        cout << "Left Child = " << ht[i].lchild << ", ";
        cout << "Right Child = " << ht[i].rchild << ", ";
        cout << "Flag = " << ht[i].flag << endl;
    }
    CreateHCode();
    for (int in = 0; in < n; ++in) {
        cout<<ht[in].data<<" : "<<hcd[in]<<endl;
    }
    return 0;
}

