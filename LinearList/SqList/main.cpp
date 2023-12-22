//
// Created by 姜杰铧 on 2023/9/22.
//
#include "SqList.h"
#include "SqList.cpp"
const int maxN = 1005;
int main() {

    //创建SqList对象
    SqList<int>myList;

    //建表
    int cnt = 0;
    int arr[maxN];
    //将arr赋值为0
    for(int i = 0; i < maxN;i++)
        arr[i] = 0;
   cout<<"请输入数组大小:"<<endl;
   cin>>cnt;
   cout<<"请输入数组元素:"<<endl;
   for(int i = 0; i < cnt;i++)
       cin>>arr[i];
   cnt--;
   myList.creatList(arr,cnt);

    //打印顺序表
    myList.dispList();

    //表尾添加元素
    myList.add(10);
    myList.dispList();

    //在序号2的位置插入元素4
    myList.insert(2,4);
    myList.dispList();

    //删除序号3的元素
    myList.remove(3);
    myList.dispList();

    //获取序号1的元素
    int e;
    myList.getElem(1,e);
    myList.dispList();

    //删除3元素
    myList.removeNo(myList,3);
    myList.dispList();
    cout<<"after merge:"<<endl;
    //演示归并
    SqList<int>A,B,C;
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6,8};
    A.creatList(a,4);
    A.dispList();
    B.creatList(b,3);
    B.dispList();
    C.merge(A,B,C);

    C.dispList();
    return 0;}