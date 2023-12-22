//
// Created by 姜杰铧 on 2023/10/11.
//
#include "LinkStack.cpp"
#include <iostream>

using namespace std;

int main() {
    LinkStack<int> stack;

    // 测试empty和push
    if(stack.empty()) {
        cout << "栈为空" << endl;
    }

    for(int i = 1; i <= 5; i++) {
        stack.push(i);
    }

    // 测试getTop
    int top;
    stack.getTop(top);
    cout << "栈顶元素为:" << top << endl;

    // 测试pop
    int popElement;
    stack.pop(popElement);
    cout << "弹出的栈顶元素为:" << popElement << endl;

    // 再次测试getTop
    stack.getTop(top);
    cout << "弹出栈顶元素后,栈顶元素变为:" << top << endl;

    // 测试栈不为空
    if(!stack.empty()) {
        cout << "栈不为空" << endl;
    }
    cout<<"此时栈为:"<<endl;
    stack.disp();
    cout<<"\n";
    cout<<"逆转后:"<<endl;
    stack.reverse();
    stack.disp();
    cout<<"\n";
    if(!stack.empty())
        throw "栈空";
    return 0;
}