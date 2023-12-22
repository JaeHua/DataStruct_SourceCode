//
// Created by 姜杰铧 on 2023/9/27.
//
#ifndef CPP_CDLINKLIST_H
#define CPP_CDLINKLIST_H
template<typename T>
//创建结点类型
struct DLinkNode
{
    T data; //数据域
    DLinkNode<T>* next; //后驱结点
    DLinkNode<T>* prev; //前驱结点
    DLinkNode() :next(nullptr), prev(nullptr) {}   //构造函数
    DLinkNode(T d) :data(d), next(nullptr), prev(nullptr) {}   //重载构造函数

};
template<typename T>
class CDLinkList
{
public:
    DLinkNode<T>*dhead;
    CDLinkList()
    {
        dhead = new DLinkNode<T>();
        dhead->next = dhead;
        dhead->prev = dhead;
    }
    ~CDLinkList()
    {
        DLinkNode<T>*pre,*p;
        pre = dhead;
        p = pre->next;
        while(p!=dhead)
        {
            delete pre;
            pre = p;
            p = p ->next;
        }
        delete pre;
    }


};
#endif //CPP_CDLINKLIST_H
