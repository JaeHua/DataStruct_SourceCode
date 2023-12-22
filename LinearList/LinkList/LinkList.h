//
// Created by 姜杰铧 on 2023/9/22.
//

#ifndef CPP_LINKLIST_H
#define CPP_LINKLIST_H
#include <iostream>
using namespace std;
template<typename T>
struct  LinkNode  //单链表结点类型
{
    T data;  //数据域
     LinkNode<T>*next;  //指针域
     LinkNode():next(nullptr){} //构造函数
     LinkNode(T d):data(d),next(nullptr){} //构造函数
};
template<typename T>
class LinkList
{
public:
    LinkNode<T>*head;  //单链表头指针
    //头插法建表
    void createListF(T a[],int n);

    //尾插法建表
    void createListR(T a[],int n);

    //返回序列为i的结点
    LinkNode<T>*getI(int i);

    //添加结点到单链表尾部
    void add(T e);

    //求单链表长度
    int getLength();

    //求单链表序号为i的结点值
    bool getElem(int i,T&e);

    //设置单链表序号为i的元素值
    bool setElem(int i,T e);

    //查找第一个为e的1元素序号
    int getNo(T e);

    //在序号i插入元素
    bool insert(int i,T e);

    //删除序号为i的元素
    bool remove(int i);

    //打印输出链表
    void dispList();

    //翻转链表
    void reverse();

    //归并算法
    void merge(LinkList<T> A,LinkList<T> B,LinkList<T>&C);

    //构造函数
    LinkList();

    //析构函数
    ~LinkList();


};
#endif //CPP_LINKLIST_H
