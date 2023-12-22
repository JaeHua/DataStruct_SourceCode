#pragma once
//
// Created by 姜杰铧 on 2023/9/27.
//

#ifndef LINEARLIST_DLINKLIST_H
#define LINEARLIST_DLINKLIST_H

#endif //LINEARLIST_DLINKLIST_H

template<typename T>
//创建结点类型
struct DLinkNode
{
    T data; //数据域
    DLinkNode<T>* next; //后驱结点
    DLinkNode<T>* prev; //前驱结点
    DLinkNode() :next(nullptr), prev(nullptr) {}   //构造函数
    DLinkNode(T d) :data(d), next(nullptr), prev(nullptr) {}   //重载构造函数

};
template<typename T>
//双链表类
class DlinkList
{
public:
    DLinkNode<T>* dhead;    //双链表头结点
    DlinkList() {
        dhead = new DLinkNode<T>();
        dhead->next = nullptr;
        dhead->prev = nullptr;
    }
    void createListF(T a[], int n);    //头插法创建双链表
    void createListR(T a[], int n);    //尾插法创建双链表
    DLinkNode<T>* getI(int i);    //获取第i个元素
    bool insert(int i, T e);    //插入元素
    bool remove(int i);    //删除元素
    void dispList();    //输出双链表
};


