//
// Created by jjh on 2023/12/28.
//

#ifndef CPP_BSTREE_H
#define CPP_BSTREE_H
#include <vector>
using namespace std;
template <typename T1,typename T2>
struct BSTNode{  //二叉排序树
    T1 key; //存放关键字
    T2 data;//存放数据项
    BSTNode*lchild;
    BSTNode*rchild;
    BSTNode(T1 k,T2 d)
    {
        key = k;
        data = d;
        lchild = rchild = nullptr;
    }
};
template <typename T1,typename T2>
class BSTree
{
public:
    BSTNode<T1,T2>*r;   //二叉排序树根结点
    BSTNode<T1,T2>*f;   //用于临时存储待删除结点的双亲结点
    BSTree()
    {
        r = nullptr;
        f = nullptr;
    }
//    void Destoryy(BSTNode<T1,T2>*b)
//    {
//        if(b!= nullptr)
//        {
//            Destoryy(b->lchild);
//            Destoryy(b->rchild);
//            delete b;
//        }
//    }
//    ~BSTree()
//    {
//       Destoryy(r);
//       r = nullptr;
//    }
    void InsertBST(T1 k,T2 d);//插入结点
    BSTNode<T1,T2>* InsertBST1(BSTNode<T1,T2>*p,T1 k,T2 d);
    void CreateBST(vector<T1>&a,vector<T2>&b);//创建二叉树
    BSTNode<T1,T2>*SearchBST(T1 k) ;//查找关键字为k的结点
    BSTNode<T1,T2>*SearchBST1(BSTNode<T1,T2>*p,T1 k);
    bool DeleteBST(T1 k);
    bool DeleteBST1(BSTNode<T1,T2>*p,T1 k,int flag);
    bool DeleteNode(BSTNode<T1,T2>*p,BSTNode<T1,T2>*f,int flag);
};




#endif //CPP_BSTREE_H
