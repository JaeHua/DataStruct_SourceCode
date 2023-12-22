//
// Created by 姜杰铧 on 2023/10/14.
//
#include <iostream>
#include "CSQueue.cpp"

using namespace std;

int main() {

    CSQueue<int> q;

    // 测试入队
    for(int i=1; i<=5; i++) {
        if(q.push(i)) {
            cout << i << " pushed to queue" << endl;
        } else {
            cout << "Queue is full!" << endl;
            break;
        }
    }

    // 测试获取队头
    int head;
    if(q.getHead(head)) {
        cout << "Queue head is: " << head << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    // 测试出队
    int x;
    if(q.pop(x)) {
        cout << x << " popped from queue" << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    // 再次获取队头
    if(q.getHead(head)) {
        cout << "New queue head is: " << head << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    return 0;
}
