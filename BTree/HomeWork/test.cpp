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
vector<string>leaf;
vector<vector<string>>MyNode;
struct BTNode
{
    string data;
    BTNode*lchild;
    BTNode*rchild;
    BTNode():lchild(nullptr),rchild(nullptr){}
    BTNode(string d)
    {
        data = d;
        lchild = rchild = nullptr;
    }
};
class BTree {
public:
    BTNode *root;//根结点
    BTree() { root = nullptr; }//构造空树
    void CreateBTree(string str) {
        stack<BTNode*>st;//存储栈
        BTNode*p;
        bool flag;
        int i = 0;
        while(i < str.length())
        {
            string s = "";
            if(str[i] <'0' || str[i] >'9')s = str[i];
            else {
                while (str[i] >= '0' && str[i] <= '9') {
                    s += str[i];
                    i++;
                }
                i--;
            }
            if(s == "(")
            {
                st.push(p);
                flag = true;
            }
            else if(s == ")")
            {
                st.pop();
            }
            else if(s == ",")
            {
                flag = false;
            }
            else
            {
                p = new BTNode(s);
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
//            switch (s) {
//                case "(":   //表明刚刚创建的结点有孩子
//                    st.push(p);
//                    flag = true;
//                    break;flag = false;
//                case ')':       //说明栈顶结点的子树处理完了
//                    st.pop();
//                    break;
//                case ',':   //说明栈顶结点有右孩子
//                    flag = false;//表示开始处理栈顶结点的右孩子
//                    break;
//                default:
//                    p = new BTNode(str[i]);
//                    if(root == nullptr)
//                        root = p;
//                    else
//                    {
//                        if(flag && !st.empty())//新结点作为左孩子结点
//                            st.top()->lchild = p;
//                        else if(!st.empty())
//                            st.top()->rchild = p;
//                    }
//                    break;
//            }

        }
    }
    void DispBTree()//括号表示法输出
    {
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
    void dispNode1(BTNode*root)
    {
        queue<BTNode*>q;
        if(root == nullptr)return;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            MyNode.push_back(vector<string>());
            for (int i = 0; i < n; ++i) {
                BTNode*b = q.front();q.pop();
                MyNode.back().push_back(b->data);
                if(b->lchild)q.push(b->lchild);
                if(b->rchild)q.push(b->rchild);
            }
        }
    }
    void dispNode()
    {
        dispNode1(root);
    }
};
int main(){
    BTree bt;
    string s;
    ifstream ifs;
    ifs.open("in.txt");
    ifs>>s;
    bt.CreateBTree(s);
//    bt.DispBTree();
    bt.dispLeaf();
    for(int i = 0; i < leaf.size()-1;i++)
        cout<<leaf[i]<<" ";
    cout<<leaf.back()<<endl;
    reverse(leaf.begin(),leaf.end());
    for(int i = 0; i < leaf.size()-1;i++)
        cout<<leaf[i]<<" ";
    cout<<leaf.back()<<endl;
    bt.dispNode();
    for(int i = 0; i < MyNode.size();i++)
        for (int j = 0; j < MyNode[i].size(); ++j) {
            cout<<MyNode[i][MyNode[i].size()-j-1]<<" ";
        }
    ifs.close();
    return 0;
}