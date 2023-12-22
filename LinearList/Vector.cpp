//
// Created by 刘禧 on 2023/9/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int>myv;     //定义vector容器myv
    vector<int>::iterator it;   //定义myv的正向迭代器it
    myv.push_back(1);       //myv尾部添加元素1
    it = myv.begin();       //it迭代器指向开头元素1
    myv.insert(it,2);   //在it指向的元素前面插入2
    myv.push_back(3);       //myv尾部添加元素3
    myv.push_back(4);       //myv尾部添加元素4
    it = myv.end();         //it迭代器指向尾元素4的后面
    it--;                   //it迭代器指向尾元素4
    myv.erase(it);  //删除元素4
    for (it = myv.begin(); it!=myv.end() ; it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    //vector的排序
    sort(myv.begin(),myv.end());
    for (it = myv.begin(); it!=myv.end() ; it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    sort(myv.begin(),myv.end(),greater<int>());
    for (it = myv.begin(); it!=myv.end() ; it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}