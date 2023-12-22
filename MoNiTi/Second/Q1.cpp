//
// Created by jjh on 2023/12/1.
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
int a[105];
LinkNode<int>*ld =new LinkNode<int>();;
void creat(int n)
{

    LinkNode<int>*tail = ld;
    for(int i = 1; i <= n;i++)
    {
        LinkNode<int>*p = new LinkNode<int>(a[i]);
        tail->next = p;
        tail = p;
    }
    tail->next = nullptr;
}
void init()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n;i++)
        cin>>a[i];
    creat(n);
}
void disp()
{
    LinkNode<int>*p = ld->next;
    while(p!= nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void solve()
{
    LinkNode<int>*head1 = new LinkNode<int>();
    LinkNode<int>*head2 = new LinkNode<int>();
    LinkNode<int>*r1 = head1,*r2 = head2;
    LinkNode<int>*p = ld->next;
    while(p!= nullptr)
    {
        LinkNode<int>*s = new LinkNode<int>(p->data);
        if(p->data < 0)
        {

            r1->next = s;
            r1 = s;
        }else
        {
            r2->next = s;
             r2 = s;
        }
        p = p->next;
    }
    r1->next = nullptr;
    r2->next = nullptr;
    ld->next = nullptr;
    if(head2->next!= nullptr)
        r1->next = head2->next;
    if(head1->next!= nullptr)
        ld->next = head1->next;

}
int main(){
    init();
    disp();
    solve();
    cout<<'\n';
    disp();
    return 0;
}