//
// Created by 姜杰铧 on 2023/11/3.
//
/*
 * 目标:用两个栈来实现一个队列类，包含函数判断队列是否为空，进队，出队运算
 * */
#include <iostream>
#include <stack>
using namespace std;
template<typename T>
stack<T>st1;
template<typename T>
stack<T>st2;
template<typename T>
class stack_queue{
public:
    bool push(T e)
    {
        st1<T>.push(e);
    }
    T pop()
    {
        while (!st1<T>.empty())
        {
            st2<T>.push(st1<T>.top());
            st1<T>.pop();

        }
       T e = st2<T>.top();
        st2<T>.pop();
        return e;
    }
    T peek()//返回队列头元素
    {
        while (!st1<T>.empty())
        {
            st2<T>.push(st1<T>.top());
            st1<T>.pop();

        }
        return st2<T>.top();
    }
    bool empty()
    {
        return st1<T>.empty()&&st2<T>.empty();
    }
};
int main()
{
    stack_queue<int>q;
    // 测试入队
    q.push(1);
    q.push(2);
    q.push(3);

    // 测试出队
    cout << q.pop() << endl; // 1
    cout << q.pop() << endl; // 2
    // 测试队头元素
    cout << q.peek() << endl; // 3

    // 测试判空
    q.pop();
    if(q.empty()) {
        cout << "EMPTY!" << endl;
    } else {
        cout << "NOTEMPTY!" << endl;
    }
    return 0;
}