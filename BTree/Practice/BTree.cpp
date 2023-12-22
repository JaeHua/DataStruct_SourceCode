//
// Created by jjh on 2023/11/22.
//
#include <iostream>
#include <stack>
using namespace std;
struct  BTNode{
    char data;  //数据元素
    BTNode*lchild;//左子结点
    BTNode*rchild;//右子结点
    BTNode():lchild(nullptr),rchild(nullptr){}//构造函数
    BTNode(char d){
        data = d;
        lchild = rchild = nullptr;  //重载构造函数
    }
};
class BTree
{
public:
    BTNode*root;
    BTree(){root = nullptr;}
    //构造二叉树
    void CreateBTree(string s)
    {
        int len = s.length();
        if(len == 0)return;
        bool flag = false;
        int i = 0;
        stack<BTNode*>st;
        BTNode*p;
        while (i<s.length())
        {
            if(s[i] == '(')
            {
                st.push(p);
                flag = true;
            }
            else if(s[i] == ')')
            {
                st.pop();
            }
            else if(s[i] == ',')
            {
                flag = false;
            }
            else
            {
                p = new BTNode(s[i]);
                if(root == nullptr)
                    root = p;
                else
                {
                    if(flag && !st.empty())//新结点作为左孩子结点
                        st.top()->lchild = p;
                    else if(!st.empty())
                        st.top()->rchild = p;
                }
            }
            i++;
        }
    }
    void DispBTree()//输出二叉树
    {
        DispBTree1(root);
    }
    void DispBTree1(BTNode*b)
    { if(b!= nullptr)
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
int main() {
    BTree tree;
    string input = "A(B(C,D(E,F)),G)";

    // 创建二叉树
    tree.CreateBTree(input);

    // 输出二叉树
    tree.DispBTree();

    return 0;
}