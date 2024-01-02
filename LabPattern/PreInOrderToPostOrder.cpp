//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
string pre,in;
struct BTNode
{
    char d;
    BTNode*l;
    BTNode*r;
    BTNode(){l = r = nullptr;}
    BTNode(int da){d = da;l = r = nullptr;}
};

//void createTree(BTNode*&bt,int index,string s)
//{
//    if(index>=s.length())
//    {
//        bt = nullptr;
//    }
//    else if(s[index]=='#')
//    {
//        bt = nullptr;
//    }
//    else
//    {
//        bt = new BTNode(s[index]);
//        createTree(bt->l,2*index+1);
//        createTree(bt->r,2*index+2);
//    }
//}

BTNode*creatT(string pre,int l1,int r1,string in,int l2,int r2)
{
    BTNode*b = new BTNode(pre[l1]);
    int i = l2;
    while(b->d!=in[i])i++;
    int llen = i - l2;
    int rlen = r2 - i;
    if(llen<=0)b->l= nullptr;
    else b->l = creatT(pre,l1+1,l1+llen,in,l2,i-1);
    if(rlen<=0) b->r=nullptr;
    else b->r = creatT(pre,l1+1+llen,r1,in,i+1,r2);
    return b;
}
// BTNode* Trans1(string pre,int i,string in,int j,int n)
// {
//     if(n<=0)return nullptr;
//     char d = pre[i];//鏍圭粨鐐?
//     BTNode*b = new BTNode(d);
//     int p = j;
//     while(in[p]!=d)p++;
//     int k = p - j;//宸﹀瓙鏍戠粨鐐逛釜鏁?
//     b->l = Trans1(pre,i+1,in,j,k);
//     b->r = Trans1(pre,i+k+1,in,p+1,n-k-1);
//     return b;
// }
// void Trans(BTNode*bt,string pre,string in)
// {
//     int n = pre.length();
//     bt = Trans1(pre,0,in,0,n);
// }
void postOrder(BTNode*bt)
{
    if(bt==nullptr)return;
    postOrder(bt->l);
    postOrder(bt->r);
    cout<<bt->d;
}
int main(){
    cin>>pre>>in;
    BTNode*bt;
    bt = creatT(pre,0,pre.length(),in,0,pre.length());
    postOrder(bt);
    return 0;
}
/*
abdecfg
dbeafcg
*/