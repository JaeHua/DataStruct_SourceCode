//
// Created by 姜杰铧 on 2023/9/27.
//
#include "DLinkList.h"
#include <iostream>
using namespace std;
template <typename T>
//头插法创建双链表
void DlinkList<T>::createListF(T a[],int n)
{
    DLinkNode<T>*s;
    dhead = new DLinkNode<T>();
    for(int i = 0; i < n; i++)
    {
        s = new  DLinkNode<T>(a[i]);
        //双链表经典四步
        s->next = dhead->next;
        if(dhead->next!= nullptr)
            dhead->next->prev = s;
        dhead->next = s;
        s->prev = dhead;

    }
}
template <typename T>
//尾插法建表
void DlinkList<T>:: createListR(T a[],int n)
{
    DLinkNode<T>*s,*r;
    cout<<1<<endl;

    r = dhead;
    cout<<2<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"looping"<<endl;
        s = new DLinkNode<T>(a[i]);

        cout<<3<<endl;
        r->next = s;
        cout<<4<<endl;
        s->prev = r;
        r = s;
    }
    r->next = nullptr;
}
//插入
template <typename T>
DLinkNode<T>* DlinkList<T>::getI(int i) {
    if(i<-1)    //头结点为-1
        return nullptr;
    DLinkNode<T>*p = dhead;
    int j = -1;
    while(j<i&&p!= nullptr)
    {
        j++;
        p = p->next;
    }
  return p;
}
template<typename T>
//插入
bool DlinkList<T>::insert(int i, T e) {
    if(i<0) return false;   //插入失败
    DLinkNode<T>*s = new DLinkNode<T>(e);   //建立新结点
    DLinkNode<T>*p = getI(i-1); //查找序号为i-1的结点
    if(p!= nullptr)
    {
        s->next = p->next;
        if(p->next!= nullptr)
            p->next->prev = s;
        p->next = s;
        s->prev = p;
        return true;
    }
    else
        return false;
}
template<typename T>
//删除结点ss
bool DlinkList<T>::remove(int i) {
    if(i<0)return false;    //删除失败
    DLinkNode<T>*p = getI(i);   //找到要删除的结点
    if(p!= nullptr)
    {
        p->prev->next = p->next;
        if(p->next!= nullptr)
            p->next->prev = p->prev;
        delete p;
        return true;
    }
    else
        return false;
}
template<typename T>
//打印双链表
void DlinkList<T>::dispList()
{
    DLinkNode<T>*p = dhead->next;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

