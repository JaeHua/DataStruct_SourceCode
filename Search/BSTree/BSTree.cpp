//
// Created by jjh on 2023/12/28.
//
#include <iostream>
#include "BSTree.h"
template <typename T1,typename T2>
void BSTree<T1, T2>::InsertBST(T1 k, T2 d) {
    r = InsertBST1(r,k,d);
}
template <typename T1,typename T2>
BSTNode<T1, T2> *BSTree<T1, T2>::InsertBST1(BSTNode<T1, T2> *p, T1 k, T2 d) {
    //在以p为根的BST中插入关键字为k的结点
    if(p == nullptr)
        p = new BSTNode<T1,T2>(k,d);
    else if(k<p->key)
        p->lchild = InsertBST1(p->lchild,k,d);
    else if(k>p->key)
        p->rchild = InsertBST1(p->rchild,k,d);
    else
        p->data = d;
    return p;
}
template<typename T1, typename T2>
void BSTree<T1, T2>::CreateBST(vector<T1> &a, vector<T2> &b) {
    r = new BSTNode<T1,T2>(a[0],b[0]);
    for(int i = 1; i < a.size();i++)
        InsertBST(a[i],b[i]);
}
template<typename T1, typename T2>
BSTNode<T1, T2> *BSTree<T1, T2>::SearchBST(T1 k) {
    return SearchBST1(r,k);
}
template<typename T1, typename T2>
BSTNode<T1, T2> *BSTree<T1, T2>::SearchBST1(BSTNode<T1, T2>*p, T1 k) {
    if(p == nullptr)return nullptr;
    if(p->key==k)return p;
    if(k < p->key)
        return SearchBST1(p->lchild,k);
    else
        return SearchBST1(p->rchild,k);
}
template<typename T1, typename T2>
bool BSTree<T1, T2>::DeleteNode(BSTNode<T1, T2> *p, BSTNode<T1, T2> *f, int flag) {
    if(p->rchild == nullptr)//结点p只有左孩子(含p为叶子的情况)
    {
        if(flag==-1)    //结点p为根结点
            r = p->lchild;
        else if(flag ==0)//p为双亲的左孩子
            f->lchild = p->lchild;
        else
            f->rchild = p->lchild;
    }
    else if(p->lchild== nullptr)
    {
        if(flag==-1)    //结点p为根结点
            r = p->rchild;
        else if(flag ==0)//p为双亲的左孩子
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild;
    }
    else
    {
        BSTNode<T1,T2>*f1 = p;
        BSTNode<T1,T2>*q = p->lchild;
        if(q->rchild== nullptr)
        {
            p->key = q->key;
            p->data = q->data;
            p->lchild = q->lchild;
        }
        else
        {
            while (q->rchild!= nullptr)
            {
                f1 = q;
                q = q->rchild;
            }
            p->key = q->key;
            p->data = q->data;
            f1->rchild = q->lchild;//删除了q
        }
    }
}

template<typename T1, typename T2>
bool BSTree<T1, T2>::DeleteBST1(BSTNode<T1, T2> *p, T1 k, int flag) {
    if(p== nullptr)return false;
    if(p->key == k)
        return DeleteNode(p,f,flag);
    if(k<p->key)
    {
        f = p;
        return DeleteBST1(p->lchild,k,0);//0表示其是ta双亲结点的左孩子
    }
    else
    {
        f = p;
        return DeleteBST1(p->rchild,k,1);//右子树中递归查找
    }
}

template<typename T1, typename T2>
bool BSTree<T1, T2>::DeleteBST(T1 k) {
    f = nullptr;
    return DeleteBST1(r,k,-1);//-1表示该结点是根结点
}
int main() {
    BSTree<int, std::string> bst;

    // 创建二叉搜索树
    std::vector<int> keys = {5, 3, 7, 2, 4, 6, 8};
    std::vector<std::string> data = {"five", "three", "seven", "two", "four", "six", "eight"};
    bst.CreateBST(keys, data);

    // 搜索关键字为4的结点
    int searchKey = 4;
    BSTNode<int, std::string>* result = bst.SearchBST(searchKey);
    if (result != nullptr) {
        std::cout << "Found: key=" << result->key << ", data=" << result->data << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // 删除关键字为3的结点
    int deleteKey = 3;
    bool deleted = bst.DeleteBST(deleteKey);
    if (deleted) {
        std::cout << "Deleted: " << deleteKey << std::endl;
    } else {
        std::cout << "Failed to delete: " << deleteKey << std::endl;
    }

    // 搜索关键字为3的结点（已删除）
    result = bst.SearchBST(deleteKey);
    if (result != nullptr) {
        std::cout << "Found: key=" << result->key << ", data=" << result->data << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}