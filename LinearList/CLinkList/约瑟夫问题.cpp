//
// Created by ������ on 2023/9/27.
//
#include <iostream>
using namespace  std;
struct Child
{
    int id;     //���
    Child*next; //���ָ��
    Child(int d):id(d),next(nullptr){}//���캯��
};
class Joseph
{
    int n, m;
    Child*head;
public:
    Joseph(int n1,int m1):n(n1),m(m1){}//���캯��
    void createList()
    {
        head = new Child(1);    //�׽��,����ͷ����!!!
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
        //n��ѭ��������n��С��
        for(int i = 1;i <= n;i++)
        {
            p = head; //ָ���׽��
            int cnt = 1; //������
            while(cnt!=m)
            {
                cnt++;
                p = p->next;
            }
            cout<<p->id<<" ";//����
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
    cout<<"������������м���:"<<endl;
    int n,m;
    cin>>n>>m;
    Joseph L(n,m);
    L.createList();
    L.Jsequence();
    return 0;
}





