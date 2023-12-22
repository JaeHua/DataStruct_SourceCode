//
// Created by ������ on 2023/10/11.
//
#include "LinkStack.cpp"
#include <iostream>

using namespace std;

int main() {
    LinkStack<int> stack;

    // ����empty��push
    if(stack.empty()) {
        cout << "ջΪ��" << endl;
    }

    for(int i = 1; i <= 5; i++) {
        stack.push(i);
    }

    // ����getTop
    int top;
    stack.getTop(top);
    cout << "ջ��Ԫ��Ϊ:" << top << endl;

    // ����pop
    int popElement;
    stack.pop(popElement);
    cout << "������ջ��Ԫ��Ϊ:" << popElement << endl;

    // �ٴβ���getTop
    stack.getTop(top);
    cout << "����ջ��Ԫ�غ�,ջ��Ԫ�ر�Ϊ:" << top << endl;

    // ����ջ��Ϊ��
    if(!stack.empty()) {
        cout << "ջ��Ϊ��" << endl;
    }
    cout<<"��ʱջΪ:"<<endl;
    stack.disp();
    cout<<"\n";
    cout<<"��ת��:"<<endl;
    stack.reverse();
    stack.disp();
    cout<<"\n";
    if(!stack.empty())
        throw "ջ��";
    return 0;
}