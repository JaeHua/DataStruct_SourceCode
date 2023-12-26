//
// Created by 姜杰铧 on 2023/11/8.
//
#include <string>
#include <vector>

using namespace std;
#ifndef CPP_BTREE_H
#define CPP_BTREE_H
//二叉链结点类型
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

class BTree {

public:
    BTNode*root;//根结点
    BTree(){root = nullptr;}//构造空树
    void CreateBTree(string str);//创建二叉链存储结构
    void DispBTree();//括号表示法输出
    void DispBTree1(BTNode*b);//被DispBTree函数调用
    void preOrder(BTNode*b);
    void postOrder(BTNode*b);
    void midOrder(BTNode*b);
    void levelOrder(BTNode*b);
    BTNode*FindNode(char x);//查找某个值
    BTNode*FindNode1(BTNode*b,char x);
    int Height();//求二叉树高度
    int Height1(BTNode*b);
    int NodeCount1(BTNode*b);//求二叉树结点个数
    int NodeCount2(BTNode*b);//直接递归求解
    int NodeCount();//以先序来求结点个数
    void DispLeaf1(BTNode*b);
    void DispLeaf();//从左到右输出叶子节点
    void DestoryBTree(BTNode*b);//释放所有空间
    void Swap1(BTNode*b);//交换所有左右子树
    void Swap();
    int Level1(BTNode*b,char x,int h);//求指定结点所在层次
    int Level(char x);
    void Kcount1(BTNode*b,int h,int k,int &cnt);//求第k层的结点个数
    int Kcount(int k);
    void Anscestor1(BTNode*b,char x,vector<char>path,vector<char>&res);//求解x的所有祖先
    void Anscestor(char x);
    void preOrder2(BTNode*b);//非递归式先序遍历
    string PreOrderSeq(BTNode*b);//先序遍历产生序列
    BTNode* ReversePreOrderSeq1(string s,int &i);//反序列
    void ReversePreOrderSeq(BTree&bt,string s);
    BTNode* findSibling(struct BTNode* root, char x);//找到结点值为x的兄弟结点
    ~BTree()//自动析构
    {
        DestoryBTree(root);
        root = nullptr;
    }
};


#endif //CPP_BTREE_H
