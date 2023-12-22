//
// Created by ������ on 2023/11/3.
//
/*
 * Ŀ��:������ջ��ʵ��һ�������࣬���������ж϶����Ƿ�Ϊ�գ����ӣ���������
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
    T peek()//���ض���ͷԪ��
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
    // �������
    q.push(1);
    q.push(2);
    q.push(3);

    // ���Գ���
    cout << q.pop() << endl; // 1
    cout << q.pop() << endl; // 2
    // ���Զ�ͷԪ��
    cout << q.peek() << endl; // 3

    // �����п�
    q.pop();
    if(q.empty()) {
        cout << "EMPTY!" << endl;
    } else {
        cout << "NOTEMPTY!" << endl;
    }
    return 0;
}