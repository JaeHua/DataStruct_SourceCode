//
// Created by 姜杰铧 on 2023/10/11.
//

#ifndef CPP_LINKSTACK_H
#define CPP_LINKSTACK_H

template<typename T>
struct LinkNode{
    T data;     //数据域
    LinkNode*next;  //指针域
    LinkNode():next(nullptr){}  //默认构造
    LinkNode(T d):data(d),next(nullptr){}  //有参构造
};
template<typename T>
class LinkStack {
public:
    LinkNode<T>*head;       //链栈的头结点
    LinkStack();            //构造函数
    ~LinkStack();           //析构函数
    bool empty();           //判断栈是否为空
    bool push(T e);         //入栈算法
    bool pop(T &e);          //出栈算法
    bool getTop(T&e);       //取栈顶元素
    void disp();            //显示
    void reverse();         //逆置
};


#endif //CPP_LINKSTACK_H
