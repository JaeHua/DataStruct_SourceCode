//
// Created by 姜杰铧 on 2023/9/27.
//

#ifndef CPP_CLINKLIST_H
#define CPP_CLINKLIST_H

#endif //CPP_CLINKLIST_H
template<typename T>
struct  LinkNode  //单链表结点类型
{
    T data;  //数据域
    LinkNode<T>*next;  //指针域
    LinkNode():next(nullptr){} //构造函数
    LinkNode(T d):data(d),next(nullptr){} //构造函数
};
template<typename T>
class CLinkList
{
public:
    LinkNode<T>*head;   //循环单链表头结点和普通单链表头结点无区别
    CLinkList()
    {
        head = new LinkNode<T>();   //循环单链表的头结点
        head->next = head;  //创建一个空循环单链表
    }
    ~CLinkList()
    {
        LinkNode<T>*pre,*p;
        pre = head;
        p = head->next;
        while(p!=head)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
}