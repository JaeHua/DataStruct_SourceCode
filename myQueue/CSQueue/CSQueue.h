//
// Created by 姜杰铧 on 2023/10/14.
//

#ifndef CPP_CSQUEUE_H
#define CPP_CSQUEUE_H

const int MaxSize = 100;    //队列的容量
template<typename T>
class CSQueue {         //循环队列模板类
public:
    T*data;     //存放队列中的元素
    int front,rear; //队头指针和队尾指针
    CSQueue();  //默认构造函数
    ~CSQueue(); //析构函数
    bool empty();   //判队空运算
    bool push(T e); //进队列运算
    bool pop(T&e);  //出队列运算
    bool getHead(T&e);  //取队头元素
};


#endif //CPP_CSQUEUE_H
