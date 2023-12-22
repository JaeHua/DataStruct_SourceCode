//
// Created by 姜杰铧 on 2023/11/4.
//
/*
 * 两个带头结点单链表，头结点指针分别为A和B，结点个数分别为m和n,均按结点值递增有序，每个单链表吧中的结点值唯一
 * */
#include <iostream>
using namespace std;
template<typename T>
struct LinkNode
{
    T data;
    LinkNode<T>*next;
    LinkNode():next(nullptr){}
    LinkNode(T d):data(d),next(nullptr){}
};
template<typename T>
class LinkList{
public:
    LinkNode<T> *head;
    LinkList()
    {
        head = new LinkNode<T>();
    }
    void creatListR(T *a,int n)
    {
        LinkNode<T>*r = head;
        for(int i = 0; i < n; i++)
        {
            LinkNode<T>*s = new LinkNode<T>(a[i]);
            r->next = s;
            r = s;
        }
        r->next = nullptr;
    }

};
template<typename T>
LinkList<T> getTheSame(LinkList<T>list1,LinkList<T>list2)
{
    LinkList<T>tmp;
    LinkNode<T>*p = list1.head->next,*q = list2.head->next,*r = tmp.head;
    while(p!= nullptr&&q!= nullptr)
    {
        if(p->data == q->data)
        {
            LinkNode<T>*s = new LinkNode<T>(p->data);
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
        else if(p->data > q->data)
            q = q->next;
        else
            p = p->next;
    }
    r->next = nullptr;
    return tmp;
}
int main() {
    int a1[] = {1, 3, 5, 7, 9};
    int a2[] = {2, 3, 6, 8};

    LinkList<int> list1;
    list1.creatListR(a1, 5);
    cout<<"running"<<endl;
    LinkList<int> list2;
    list2.creatListR(a2, 4);
    cout<<"running"<<endl;
    LinkList<int> result = getTheSame(list1, list2);
    cout<<"running"<<endl;
    // 输出结果
    LinkNode<int>* p = result.head->next;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}