//
// Created by jjh on 2023/12/4.
//
#include <bits/stdc++.h>
using namespace std;
struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;

};
int n;
void create(BTNode*&bt,int a[],int index)
{
    if(index>=n)
    {
        bt= nullptr;
        return;
    }
    if(a[index] == -1)
    {
        bt = nullptr;
        return;
    }
    bt = new BTNode();
    bt->data = a[index];
    create(bt->lchild,a,2*index+1);
    create(bt->rchild,a,2*index+2);
}
bool is_full_bttree(BTNode*bt)
{
    if(bt== nullptr)
        return true;
   if((bt->lchild!= nullptr&&bt->rchild== nullptr)||(bt->lchild== nullptr && bt->rchild!= nullptr))
       return false;
   return is_full_bttree(bt->lchild)&& is_full_bttree(bt->rchild);
};
int main(){

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    BTNode*bt;
    create(bt,a,n);
    if(is_full_bttree(bt))
        cout<<"该树是满二叉树"<<endl;
    else
        cout<<"该树不是满二叉树"<<endl;
    return 0;
}
