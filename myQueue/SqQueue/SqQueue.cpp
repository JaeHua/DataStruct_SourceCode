//
// Created by 姜杰铧 on 2023/10/14.
//

#include "SqQueue.h"
template<typename T>
SqQueue<T>::SqQueue() {
    data = new T[MaxSize];  //为data分配容量为maxsize的空间
    front = rear = -1;      //队头和队尾指针置空值
}

template<typename T>
SqQueue<T>::~SqQueue() {
    delete []data;  //释放空间
}

template<typename T>
bool SqQueue<T>::empty() {
    return front == rear;   //队空的判定
}

template<typename T>
bool SqQueue<T>::push(T e) {
    if(rear == MaxSize - 1)return false;    //队满
    rear++;
    data[rear] = e;
    return true;
}

template<typename T>
bool SqQueue<T>::pop(T &e) {
    if(front == rear)   //队空
        return false;
    front++;
    e = data[front];
    return true;
}

template<typename T>
bool SqQueue<T>::getHead(T &e) {
    if(front == rear)return false;
    //front是在队头元素的前一个
    int head = front + 1;
    e  = data[head];
    return true;
}

