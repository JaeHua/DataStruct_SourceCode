//
// Created by ������ on 2023/10/18.
//

#include <iostream>
#include "LinkQueue.cpp"

using namespace std;

void Jsequence(int n,int m)
{
    int x;
    LinkQueue<int>qu;
    for(int i = 1; i <= n; i++)
        qu.push(i);
    for(int i = 1; i <= n;i++)//n��ѭ����ջ
    {
        int j = 1;
        while(j<= m-1)
        {
            qu.pop(x);
            qu.push(x);
            j++;
        }
        qu.pop(x);//���ӵ�m��
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    /**
    LinkQueue<int> q;

    // �������
    for(int i = 1; i <= 5; i++) {
        q.push(i);
    }

    // ���Ի�ȡͷԪ��
    int head;
    q.getHead(head);
    cout << "Queue head: " << head << endl;

    // ���Գ���
    while(!q.empty()) {
        int e;
        q.pop(e);
        cout << "Popped element: " << e << endl;
    }

    // ���Կն��г���
    int e;
    if(q.pop(e)) {
        cout << "Popped element from empty queue? " << e << endl;
    } else {
        cout << "Pop failed on empty queue." << endl;
    }

    // ���������һЩԪ��
    for(int i = 1; i <= 3; i++) {
        q.push(i);
    }

    // ��������ʱ���в�Ϊ��
    return 0;
    */
    cout<<"����˳��:"<<endl;
    Jsequence(6,3);
    return 0;
}
