//
// Created by 刘禧 on 2023/9/28.
//
//list是一个循环双链表
#include <iostream>
#include <list>
using namespace std;
void disp(list < int >lst)
{
    list<int>::iterator it;
    for(it = lst.begin();it!=lst.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
int main()
{
    list<int>lst;       //定义list容器lst
    list<int>::iterator it,start,end;
    //添加五个整数
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);
    disp(lst);
    it = lst.begin();   //it指向首元素5
    start = ++lst.begin();  //指向第二个元素
    end = --lst.end();  //指向尾元素
    lst.insert(it,start,end);
    disp(lst);
    return 0;
}


