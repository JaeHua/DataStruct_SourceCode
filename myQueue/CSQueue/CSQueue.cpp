//
// Created by 姜杰铧 on 2023/10/14.
//

#include "CSQueue.h"
template<typename T>
CSQueue<T>::CSQueue() {
    data = new T[MaxSize];  //分配内存
    front = rear = 0;
}

template<typename T>
CSQueue<T>::~CSQueue() {
    delete []data;  //释放内存
}

template<typename T>
bool CSQueue<T>::empty() {
    return rear== front;
}

template<typename T>
bool CSQueue<T>::push(T e) {
    if((rear + 1) % MaxSize == front)   //队满上溢
        return false;
    rear = (rear + 1)%MaxSize;
    data[rear] = e;
    return true;
}
template<typename T>
bool CSQueue<T>::pop(T&e)   //取队头运算
{
    if(front == rear)return false;  //队空下溢出
    front = (front + 1)%MaxSize;
    e  = data[front];//front
    return true;
}
template<typename T>
bool CSQueue<T>::getHead(T&e)
{
    if (front == rear)return false;
    int head = (front + 1)%MaxSize;
    e = data[head];
    return true;
}
