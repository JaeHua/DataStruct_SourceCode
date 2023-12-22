//
// Created by jjh on 2023/11/18.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
vector<char>leaf;
vector<vector<char>>MyNode;
struct BTNode
{
    char data;
    BTNode*lchild;
    BTNode*rchild;
    BTNode():lchild(nullptr),rchild(nullptr){}
    BTNode(char d)
    {
        data = d;
        lchild = rchild = nullptr;
    }
};
class BTree{
public:
    BTNode*root;
    void CreateBTree(string str) {
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
    void dispLeaf1(BTNode*b)
    {
        if(b == nullptr)return;
        if(b->lchild == nullptr&&b->rchild == nullptr)
            leaf.push_back(b->data);
        dispLeaf1(b->lchild);
        dispLeaf1(b->rchild);
    }
    void dispLeaf()
    {
        dispLeaf1(root);
    }
    void dispNode(BTNode*root)
    {
        queue<BTNode*>q;
        if(root == nullptr)return;
        q.push(root);
        while (!q.empty())
        {
           int n = q.size();
           MyNode.push_back(vector<char>());
            for (int i = 0; i < n; ++i) {
                BTNode*b = q.front();q.pop();
                MyNode.back().push_back(b->data);
                if(b->lchild)q.push(b->lchild);
                if(b->rchild)q.push(b->rchild);
            }
        }
    }
    void DispBTree() {
        DispBTree1(root);
    }

    void DispBTree1(BTNode *b) {
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
};

int main(){
    string s;
    cin>>s;
    BTree bt;
    bt.CreateBTree(s);
    bt.DispBTree();


//    bt.dispLeaf();

    for(int i = 0; i < leaf.size()-1;i++)
        cout<<leaf[i]<<" ";
    cout<<leaf.back()<<endl;
//    reverse(leaf.begin(),leaf.end());
//    for(int i = 0; i < leaf.size()-1;i++)
//        cout<<leaf[i]<<" ";
//    cout<<leaf.back()<<endl;
//    bt.dispNode(bt.root);
//    for(int i = 0; i < MyNode.size();i++)
//        for (int j = 0; j < MyNode[i].size(); ++j) {
//            cout<<MyNode[i][MyNode[i].size()-j-1]<<" ";
//        }

    return 0;
}