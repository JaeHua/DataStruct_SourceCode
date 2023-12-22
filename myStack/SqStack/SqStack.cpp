//
// Created by 刘禧 on 2023/9/28.
//
#include "SqStack.h"
using namespace std;
template<typename T>
//判断栈是否为空
bool SqStack<T>::empty() {
    return top == -1;
}
template<typename T>
//进栈算法
bool SqStack<T>::push(T e) {
    if(top == MaxSize -1)
        return false;   //栈满，入栈失败
    top++;
    data[top] = e;
    return true;
}
template<typename T>
bool SqStack<T>::pop(T&e)
{
    if(empty())
        return false;   //栈空，删除元素失败
    e = data[top];
    top--;
    return true;
}
template<typename T>
bool SqStack<T>::getTop(T&e)
{
    if(empty())
        return false;//栈空，取元素失败
    e = data[top];
    return true;
}






