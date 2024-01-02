//
// Created by jjh on 2024/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

// 使用vector模拟栈
template<typename T>
class Stack {
public:
    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        vec.pop_back();
    }

    T top() {
        return vec.back();
    }

    bool empty() {
        return vec.empty();
    }

private:
    vector<T> vec;
};

// 使用vector模拟队列
template<typename T>
class Queue {
public:
    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        vec.erase(vec.begin());
    }

    T front() {
        return vec.front();
    }

    bool empty() {
        return vec.empty();
    }

private:
    vector<T> vec;
};

int main() {
    // 测试栈
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    // 测试队列
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    return 0;
}
