//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
struct BTNode
{
    char d;
    BTNode*l;
    BTNode*r;
    BTNode(){l = r = nullptr;}
    BTNode(int da){d = da;l = r = nullptr;}
};
string s;
void createTree(BTNode*&bt,int index)
{
    if(index>=s.length())
    {
        bt = nullptr;
    }
    else if(s[index]=='#')
    {
        bt = nullptr;
    }
    else
    {
        bt = new BTNode(s[index]);
        createTree(bt->l,2*index+1);
        createTree(bt->r,2*index+2);
    }
}
void level(BTNode*bt)
{
    queue<BTNode*>q;
    if(bt==nullptr)return;
    q.push(bt);
    while(!q.empty())
    {
        int n = q.size();

        for(int i = 0; i < n ; i++)
        {
            BTNode*x = q.front();q.pop();
            cout<<x->d<<" ";
            if(x->l!=nullptr)q.push(x->l);
            if(x->r!=nullptr)q.push(x->r);
        }
    }
}
void preOrder(BTNode*bt)
{
    if(bt==nullptr)return;
    cout<<bt->d<<" ";
    preOrder(bt->l);
    preOrder(bt->r);
}
int main(){
    cin>>s;
    BTNode*bt;
    createTree(bt,0);
    level(bt);
    cout<<"\n"<<endl;
    preOrder(bt);
    return 0;
}