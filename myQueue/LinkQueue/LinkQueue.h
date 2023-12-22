//
// Created by 姜杰铧 on 2023/10/18.
//

#ifndef CPP_LINKQUEUE_H
#define CPP_LINKQUEUE_H
//结点
template <typename T>
struct LinkNode
{
    T data;//结点数据域
    LinkNode*next;//指向下一个结点
    LinkNode():next(nullptr){}//构造函数
    LinkNode(T d):data(d),next(nullptr){}//重载构造函数

};
//链队类模板
template<typename T>
class LinkQueue {
public:
    LinkNode<T>*front;//队头指针
    LinkNode<T>*rear;//队尾指针
    LinkQueue();
    ~LinkQueue();
    bool empty();//判断队列是否为空
    bool push(T e);//进队运算
    bool pop(T&e);//出队运算
    bool getHead(T&e);//取队头运算
};


#endif //CPP_LINKQUEUE_H
