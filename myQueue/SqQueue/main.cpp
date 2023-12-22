//
// Created by 姜杰铧 on 2023/10/14.
//
#include "SqQueue.cpp"
#include <iostream>
using namespace std;
int main(void)
{
    SqQueue<int> q; // 创建整数队列

    // 测试插入
    q.push(1);
    q.push(2);
    q.push(3);

    // 测试获取队头元素
    int head;
    q.getHead(head);
    cout << "Queue head is: " << head << endl;

    // 测试弹出元素
    int x;
    q.pop(x);
    cout << "Popped element: " << x << endl;

    // 再次获取队头
    q.getHead(head);
    cout << "New queue head is: " << head << endl;

    // 测试判空
    if(q.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}