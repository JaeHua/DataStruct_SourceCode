//
// Created by 姜杰铧 on 2023/10/14.
//

#ifndef CPP_SQQUEUE_H
#define CPP_SQQUEUE_H

const int MaxSize = 100;    //队列的容量
template<typename T>
class SqQueue {
public:
    T*data;     //存放队列中的元素
    int front,rear;     //对头指针和队尾指针
    SqQueue();  //默认构造
    ~SqQueue(); //析构函数
    bool empty();   //判断队列是否为空
    bool push(T e); //进队列运算
    bool pop(T&e);  //出队列运算
    bool getHead(T&e);  //取队头运算
};


#endif //CPP_SQQUEUE_H
