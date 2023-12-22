//
// Created by 姜杰铧 on 2023/9/22.
//
#include "LinkList.h"
#include "LinkList.cpp"
int main(){
    //创建单链表
    LinkList<int>myList;
    int a[] = {1,3,5,7,9};
    //尾插法建表
    myList.createListR(a,5);
    myList.dispList();

    //获取序号为2的元素
    int e;
    myList.getElem(2,e);
    cout<<"Element 2 is :"<<e<<endl;

    //修改序号为3的元素为8
    myList.setElem(3,8);
    cout<<"after modify:"<<endl;
    myList.dispList()  ;

    //查找元素5的位置
    int pos = myList.getNo(5);
    cout<<"Element 5 is :"<<pos<<endl;


    //在第三个位置插入4
    myList.insert(2,4);
    myList.dispList();

    //删除第1序号位置
    myList.remove(1);
    myList.dispList();

    //翻转序列
    myList.reverse();
    myList.dispList();
    return 0;
}