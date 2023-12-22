//
// Created by 姜杰铧 on 2023/10/18.
//

#include "LinkQueue.h"
template<typename T>
LinkQueue<T>::LinkQueue() {
    front = nullptr;//队头结点置空
    rear = nullptr;//队尾结点置空
}
template<typename T>
LinkQueue<T>::~LinkQueue() {
    LinkNode<T>*pre,*p;
    pre = front;//指向头结点，开始遍历
    while(!pre)
    {
        if(pre == rear) //只有一个数据结点
            delete pre;
        else
        {
            p = pre ->next;
            while(p!= nullptr)
            {
                delete pre;
                pre = p;
                p = pre->next;
            }
            delete pre; //删除尾结点
        }
    }
}
template<typename T>
bool LinkQueue<T>::empty() {
    return rear == nullptr;//判断空运算
}
template<typename T>
bool LinkQueue<T>::push(T e)//进队运算
{
    LinkNode<T>*p = new LinkNode<T>(e);
    if(rear == nullptr)
    {
        front = rear = p;   //链队为空的情况
    }else
    {
        rear->next = p;
        rear = p;
    }
    return true;
}
template<typename T>
bool LinkQueue<T>::pop(T &e) {
    if(rear == nullptr)return false;//处理队空的情况
    LinkNode<T>*p = front;
    if(front == rear)
        front = rear = nullptr;//处理只有一个元素的情况
    else
        front = front->next;
    e = p->data;
    delete p;   //删除
    return true;
}
template<typename T>
bool LinkQueue<T>::getHead(T &e) {
    if(rear == nullptr)return false;
    e = front->data;
    return true;
}