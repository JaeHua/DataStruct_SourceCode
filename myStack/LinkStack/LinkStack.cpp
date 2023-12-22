//
// Created by 姜杰铧 on 2023/10/11.
//

#include "LinkStack.h"
#include <bits/stdc++.h>
template<typename T>
LinkStack<T>::LinkStack() {
   //分配空间给head结点
   head = new LinkNode<T>();
}

template<typename T>
LinkStack<T>::~LinkStack() {
    LinkNode<T>*pre = head;
    LinkNode<T>*p = head->next;
    while(p!= nullptr)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}
template<typename T>
bool LinkStack<T>::empty() {
    //没有数据结点
    return head->next == nullptr;
}
template<typename T>
bool LinkStack<T>::push(T e) {
    //头插入栈
    LinkNode<T>*p = new LinkNode<T>(e);
    p->next = head->next;
    head->next = p;
    return true;
}
template<typename T>
bool LinkStack<T>::pop(T &e) {
    if(head->next == nullptr)return false;
    LinkNode<T>*p = head->next;
    e = p->data;
    head->next = p->next;
    delete p;
    return true;
}
template<typename T>
bool LinkStack<T>::getTop(T &e) {
    if(head->next == nullptr)return false;
    LinkNode<T>*p = head->next;
    e = p->data;
    return true;
}
template<typename T>
void LinkStack<T>::disp() {
    LinkNode<T>*p = this->head->next;
    while(p!= nullptr)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
}
template<typename T>
void LinkStack<T>::reverse() {
    int a[1005];
    int i = 0;
    T e;
    while(!this->empty())
    {
        this->pop(e);
        a[i++] = e;
    }
    for(int j = 0; j < i ;j++)
        this->push(a[j]);
}
