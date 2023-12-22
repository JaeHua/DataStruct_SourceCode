//
// Created by jjh on 2023/12/4.
//
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
void create_list(LinkNode<T>*&l)
{
    LinkNode<T>*p,*q;
    l = new LinkNode<T>();
    p = l;
    while(1)
    {
        q = new LinkNode<T>();
        cin>>q->data;
        if(q->data<0)
            break;
        p->next = q;
        p = q;
    }
    p->next = nullptr;
}
template<typename T>
void output(LinkNode<T>*l)
{
    LinkNode<T>*p;
    p = l->next;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
template<typename T>
void solve(LinkNode<T>*&A,LinkNode<T>*&B)
{
    LinkNode<T>*p = A->next;
    LinkNode<T>*q = B->next;
    LinkNode<T>*s;
    A->next = nullptr;
    LinkNode<T>*r = A;
    while(p!= nullptr&&q!= nullptr)
    {
        if(p->data<q->data)
        {
            s = p;
            p = p->next;
            s->next = nullptr;
            r->next = s;
            r = s;
        }else
        {
            s = q;
            q = q->next;
            s->next = nullptr;
            r->next = s;
            r = s;
        }
    }
    if(p!= nullptr) {
        r->next = p;
        r = p;
    }
    else if(q!= nullptr)
    {   r->next = q;
        r = q;
    }


}
int main(){

    LinkNode<int>*A,*B;
    create_list(A);
    create_list(B);
    output(A);
    output(B);
    solve(A,B);
    output(A);
    return 0;
}