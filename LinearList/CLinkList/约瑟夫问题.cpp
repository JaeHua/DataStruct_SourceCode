//
// Created by 姜杰铧 on 2023/9/27.
//
#include <iostream>
using namespace  std;
struct Child
{
    int id;     //编号
    Child*next; //后继指针
    Child(int d):id(d),next(nullptr){}//构造函数
};
class Joseph
{
    int n, m;
    Child*head;
public:
    Joseph(int n1,int m1):n(n1),m(m1){}//构造函数
    void createList()
    {
        head = new Child(1);    //首结点,不带头结点的!!!
        Child*r = head,*p;
        for(int i = 2; i <=n;i++)
        {
            p = new Child(i);
            r->next = p;
            r = p;
        }
        r->next = head;
    }
    void Jsequence()
    {
        Child*p,*q;
        //n次循环，出列n个小孩
        for(int i = 1;i <= n;i++)
        {
            p = head; //指向首结点
            int cnt = 1; //计数器
            while(cnt!=m)
            {
                cnt++;
                p = p->next;
            }
            cout<<p->id<<" ";//出列
            q = p->next;
            p->id = q->id;
            p->next = q->next;
            delete q;
            head = p;

        }

    }
};
int main()
{
    cout<<"输入人数与出列计数:"<<endl;
    int n,m;
    cin>>n>>m;
    Joseph L(n,m);
    L.createList();
    L.Jsequence();
    return 0;
}





