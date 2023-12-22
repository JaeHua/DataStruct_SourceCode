//
// Created by 姜杰铧 on 2023/9/22.
//
#include "LinkList.h"
#include <iostream>
using namespace std;
template<typename T>
void LinkList<T>::createListF(T *a, int n) {
    for(int i = 0; i < n;i++)
    {
        //分配新结点并赋值
        LinkList<T>*s = new LinkList<T>(a[i]);
        s->next = head->next;       //头插法建表
        head->next = s;
    }
}
template<typename T>
void LinkList<T>::createListR(T *a, int n) {
    LinkNode<T>*s,*r;
    r = head;   //尾结点初始指向头结点
    for(int i = 0; i < n; i ++)
    {
        s = new LinkNode<T>(a[i]);      //分配新结点
        r->next = s;
        r = s;
    }
    r->next = nullptr;          //尾结点指向空
}
template<typename T>
LinkNode<T>* LinkList<T>::getI(int i) {
    if(i<-1)return nullptr; //序号不能为负,规定头结点为-1
    LinkNode<T>*p = head;
    int j = -1;
    while(j<i&&p!= nullptr)
    {
        j++;
        p = p->next;
    }
    return p;

}
template<typename T>
LinkList<T>::LinkList() {
    head = new LinkNode<T>();
}
template<typename T>
LinkList<T>::~LinkList() {
    LinkNode<T>*pre,*p;
    pre = head; p =head->next;
    while(p!= nullptr)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}
template<typename T>
void LinkList<T>::add(T e) {
    LinkNode<T>*s = new LinkNode<T>(e);
    LinkNode<T>*p = head;
    while(p->next != nullptr)   //尾插法建表
        p = p->next;
    p->next = s;
}
template<typename T>
int LinkList<T>::getLength() {
    LinkNode<T>*p = head;
    int cnt = 0;
    while(p->next!= nullptr)
        cnt++;
    return cnt;
}
template<typename T>
bool LinkList<T>::getElem(int i, T &e) {
    if(i<0)return -1;
    LinkNode<T>*p = getI(i);
    if(p != nullptr)
    {
        e = p->data;
        return true;
    }
    else
        return false;
}
template<typename T>
bool LinkList<T>::setElem(int i, T e) {
    LinkNode<T>*p = getI(i);
    if(p != nullptr)
    {
        p->data = e;
        return true;
    }
    else
        return false;
}
template<typename T>
int  LinkList<T>::getNo(T e) {
   int j = 0;
   LinkNode<T>*p = head->next;
    while (p!= nullptr)
    {
        if(p->data == e)
            return j;
        else
            j++;
        p = p->next;
    }
    return -1;
}
template<typename T>
bool LinkList<T>::insert(int i, T e) {
    if(i<0)return false;
    LinkNode<T>*p = getI(i - 1);
    if(p != nullptr)
    {
        LinkNode<T>*s = new LinkNode<T>(e);
        s->next = p->next;
        p->next = s;
        return true;
    }
    else
        return false;
}
template<typename T>
bool LinkList<T>::remove(int i) {
    if(i<0)return false;
    LinkNode<T>*p = getI(i - 1);
    if(p != nullptr)
    {
        LinkNode<T>*q = p->next;
        if(q!= nullptr)
        {
            p->next = q->next;
            delete q;
            return true;
        }
        return false;
    }
    return false;
}
template<typename T>
void LinkList<T>::dispList()
{
    LinkNode<T>*p = head->next;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
template<typename T>
void LinkList<T>::reverse() {
    LinkNode<T>*p = head->next,*q;
    head->next = nullptr;       //将头结点变为空
    while(p!= nullptr)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}
template<typename T>
void LinkList<T>::merge(LinkList<T> A, LinkList<T> B, LinkList<T> &C) {
    LinkNode<T>*p = A.head->next;   //p指向A的头结点
    LinkNode<T>*q = B.head->next;   //q指向B的头结点
    LinkNode<T>*r = C.head;         //r指向C的尾结点
    while(p!= nullptr&&q!= nullptr)
    {
        if(p->data<q->data)
        {
            r->next = p;
            r = p;
            p = p->next;

        }else
        {
            r->next = q;
            r = q;
            q = q->next;

        }
        r->next = nullptr;
        //剩余链全部接上
        if(p!= nullptr)r->next = p;
        if(q!= nullptr)r->next = q;
    }
}

