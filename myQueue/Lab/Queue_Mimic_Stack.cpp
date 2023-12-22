//
// Created by 姜杰铧 on 2023/11/3.
//
/*
 * 目标：用两个队列来模拟栈，包含运算判断队列为空，进栈与出栈运算
 * */

#include <iostream>
#include <queue>
using namespace std;
template<typename T>
queue<T>q1;//存储栈元素
template<typename T>
queue<T>q2;//辅助队列
template<typename T>
class queue_stack{
public:
    bool push(T e)
    {
        q2<T>.push(e);
        while(!q1<T>.empty())
        {
            q2<T>.push(q1<T>.front());
            q1<T>.pop();
        }
        swap(q1<T>,q2<T>);//两个队列也是可以swap的
    }
    T pop()
    {
        T e = q1<T>.front();
        q1<T>.pop();
        return e;
    }
    bool empty()
    {
        return q1<T>.empty();
    }
};
int main(){


    queue_stack<int> stack;

    // 入栈
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 出栈
    cout << stack.pop() << endl; // 3
    cout << stack.pop() << endl; // 2

    // 判空
    if(stack.empty()) {
        cout << "栈为空!" << endl;
    } else {
        cout << "栈不为空!" << endl;
    }

    // 再入栈
    stack.push(4);
    stack.push(5);

    // 再出栈
    cout << stack.pop() << endl; // 5
    cout << stack.pop() << endl; // 4

    return 0;
    return 0;
}