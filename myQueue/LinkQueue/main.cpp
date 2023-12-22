//
// Created by 姜杰铧 on 2023/10/18.
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
    for(int i = 1; i <= n;i++)//n重循环出栈
    {
        int j = 1;
        while(j<= m-1)
        {
            qu.pop(x);
            qu.push(x);
            j++;
        }
        qu.pop(x);//出队第m个
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    /**
    LinkQueue<int> q;

    // 测试入队
    for(int i = 1; i <= 5; i++) {
        q.push(i);
    }

    // 测试获取头元素
    int head;
    q.getHead(head);
    cout << "Queue head: " << head << endl;

    // 测试出队
    while(!q.empty()) {
        int e;
        q.pop(e);
        cout << "Popped element: " << e << endl;
    }

    // 测试空队列出队
    int e;
    if(q.pop(e)) {
        cout << "Popped element from empty queue? " << e << endl;
    } else {
        cout << "Pop failed on empty queue." << endl;
    }

    // 测试再入队一些元素
    for(int i = 1; i <= 3; i++) {
        q.push(i);
    }

    // 测试析构时队列不为空
    return 0;
    */
    cout<<"出列顺序:"<<endl;
    Jsequence(6,3);
    return 0;
}
