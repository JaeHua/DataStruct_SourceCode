//
// Created by 姜杰铧 on 2023/11/8.
//
#include <iostream>
#include "BTree.h"
#include <stack>
#include <queue>
void BTree::CreateBTree(std::string str) {
    stack<BTNode*>st;//存储栈
    BTNode*p;
    bool flag;
    int i = 0;
    while(i < str.length())
    {
        switch (str[i]) {
            case '(':   //表明刚刚创建的结点有孩子
                st.push(p);
                flag = true;
                break;
            case ')':       //说明栈顶结点的子树处理完了
                st.pop();
                break;
            case ',':   //说明栈顶结点有右孩子
                flag = false;//表示开始处理栈顶结点的右孩子
                break;
            default:
                p = new BTNode(str[i]);
                if(root == nullptr)
                    root = p;
                else
                {
                    if(flag && !st.empty())//新结点作为左孩子结点
                        st.top()->lchild = p;
                    else if(!st.empty())
                        st.top()->rchild = p;
                }
                break;
        }
        i++;
    }
}

void BTree::DispBTree() {
    DispBTree1(root);
}

void BTree::DispBTree1(BTNode *b) {
    if(b!= nullptr)
    {
        cout<<b->data;
        if(b->lchild!= nullptr||b->rchild!= nullptr)
        {
            cout<<"(";
            DispBTree1(b->lchild);
            if(b->rchild!= nullptr)
                cout<<",";
            DispBTree1(b->rchild);
            cout<<")";
        }
    }
}
void BTree::preOrder(BTNode*p) {
    if(p== nullptr)
        return;
    cout<<p->data;
    preOrder(p->lchild);
    preOrder(p->rchild);
}
void BTree::postOrder(BTNode*p) {
    if(p== nullptr)
        return;
    postOrder(p->lchild);
    postOrder(p->rchild);
    cout<<p->data;
}
void BTree::midOrder(BTNode*p) {
    if(p== nullptr)
        return;
    midOrder(p->lchild);
    cout<<p->data;
    midOrder(p->rchild);
}

BTNode *BTree::FindNode(char x) {
    return FindNode1(root,x);
}

BTNode *BTree::FindNode1(BTNode *b, char x) {
    BTNode*p;
    if(b == nullptr)return nullptr;
    else if(b->data == x)return b;
    else
    {
        p = FindNode1(b->lchild,x);
        if(p!= nullptr)
            return p;   //在左子树中找
        else
            return FindNode1(b->rchild,x);
    }
}

int BTree::Height() {
    return Height1(root);
}

int BTree::Height1(BTNode *b) {
    if(b == nullptr)return 0;//空树高度为0
    else
        return max(Height1(b->lchild), Height1(b->rchild)) + 1;
}

void BTree::DestoryBTree(BTNode *b) {
    if(b!= nullptr)
    {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        delete b;
    }
}

int BTree::NodeCount1(BTNode *b) {
    if(b == nullptr)
        return 0;
    int k = 1;//根结点计数
    int n = NodeCount1(b->lchild);
    int m = NodeCount1(b->rchild);
    return k + n + m;
}
int BTree::NodeCount() {
    return NodeCount2(root);
}

int BTree::NodeCount2(BTNode *b) {
    if(b == nullptr)return 0;
    return NodeCount2(b->lchild) + NodeCount2(b->rchild) + 1;
}

void BTree::DispLeaf1(BTNode *b) {
    if(b== nullptr)return;
    if(b->lchild== nullptr&&b->rchild== nullptr)
        cout<<b->data;
    DispLeaf1(b->lchild);
    DispLeaf1(b->rchild);
}

void BTree::DispLeaf() {
    DispLeaf1(root);

}

void BTree::Swap1(BTNode *b) {
    if(b== nullptr)return;
    Swap1(b->lchild);
    Swap1(b->rchild);
    swap(b->lchild,b->rchild);
}

void BTree::Swap() {
    Swap1(root);
}

int BTree::Level1(BTNode *b, char x, int h) {
    if(b== nullptr)return 0;
    if(b->data == x)
        return h;
    int n = Level1(b->lchild,x,h+1);
    if(n!=0)
        return n;
    else
        Level1(b->rchild,x,h+1);
}
int BTree::Level(char x) {
    return Level1(root,x,1);
}

void BTree::Kcount1(BTNode *b, int h, int k, int &cnt) {
    if(b== nullptr)return;
    if(k == h)
        cnt++;
    if(k>h)return;//剪枝
    Kcount1(b->lchild,h+1,k,cnt);
    Kcount1(b->rchild,h+1,k,cnt);
}

int BTree::Kcount(int k) {
    int cnt = 0;
    Kcount1(root,1,k,cnt);
    return cnt;
}

void BTree::Anscestor1(BTNode *b, char x,vector<char>path,vector<char>&res) {
    if( b == nullptr)return;
    path.push_back(b->data);
    if(b->data == x)
    {
        path.pop_back();
        res = path;
        return;
    }
    Anscestor1(b->lchild,x,path,res);
    Anscestor1(b->rchild,x,path,res);
}
void BTree::Anscestor(char x) {
    vector<char>path,res;
    Anscestor1(root,x,path,res);
    cout<<x<<"结点的祖先有:";
    for(char ch : res)
        cout<<ch<<" ";
    cout<<endl;
}

void BTree::preOrder2(BTNode *b) {
    if(b== nullptr)return;
    stack<BTNode*>st;   //用栈来模拟递归
    BTNode*p;
    st.push(b);
    while (!st.empty())
    {
        p = st.top();st.pop();
        cout<<p->data;
        if(p->rchild!= nullptr)
            st.push(p->rchild);
        if(p->lchild!= nullptr)
            st.push(p->lchild);
    }
    cout<<endl;
}

void BTree::levelOrder(BTNode *b) {
    //用队列来实现
    BTNode*p;
    queue<BTNode*>qu;
    if(b== nullptr)return;
    qu.push(b);
    while(!qu.empty())
    {
        p = qu.front();qu.pop();
        cout<<p->data;
        if(p->lchild!= nullptr)
            qu.push(p->lchild);
        if(p->rchild!= nullptr)
            qu.push(p->rchild);
    }
}

string BTree::PreOrderSeq(BTNode *b) {
    if(b== nullptr)return "#";
    string s(1,b->data);
    s += PreOrderSeq(b->lchild);
    s += PreOrderSeq(b->rchild);
    return s;
}

BTNode *BTree::ReversePreOrderSeq1(std::string s, int &i) {
    if(i>=s.length())return nullptr;//超界
    char d = s[i++];
    if(d == '#')return nullptr;
    BTNode*b = new BTNode(d);
    b->lchild = ReversePreOrderSeq1(s,i);
    b->rchild = ReversePreOrderSeq1(s,i);
    return b;
}

void BTree::ReversePreOrderSeq(BTree &bt, std::string s) {
    int i= 0;
    bt.root = ReversePreOrderSeq1(s,i);
}