//
// Created by ������ on 2023/11/3.
//
/*
 * Ŀ�꣺������������ģ��ջ�����������ж϶���Ϊ�գ���ջ���ջ����
 * */

#include <iostream>
#include <queue>
using namespace std;
template<typename T>
queue<T>q1;//�洢ջԪ��
template<typename T>
queue<T>q2;//��������
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
        swap(q1<T>,q2<T>);//��������Ҳ�ǿ���swap��
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

    // ��ջ
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // ��ջ
    cout << stack.pop() << endl; // 3
    cout << stack.pop() << endl; // 2

    // �п�
    if(stack.empty()) {
        cout << "ջΪ��!" << endl;
    } else {
        cout << "ջ��Ϊ��!" << endl;
    }

    // ����ջ
    stack.push(4);
    stack.push(5);

    // �ٳ�ջ
    cout << stack.pop() << endl; // 5
    cout << stack.pop() << endl; // 4

    return 0;
    return 0;
}