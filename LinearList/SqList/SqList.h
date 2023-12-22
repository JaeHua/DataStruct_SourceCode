//
// Created by 姜杰铧 on 2023/9/22.
//

#ifndef CPP_SQLIST_H
#define CPP_SQLIST_H
using namespace std;
const int initcap = 5;      //顺序表的初始容量
template<typename T>
class SqList {
public:
    T*data;                  //存放顺序表空间的指针
    int capacity;             //顺序表的容量
    int length;               //顺序表的长度
    //扩容
    void recap(int newcap);

    //建表
    void creatList(T a[],int n);

    //表尾添加元素
    void add(T e);

    //求顺序表长度
    int getLength();

    //求序号为i的元素值
    bool getElem(int i,T& e);

    //设置序号为i的元素值
    bool setElem(int i,T e);

    //查找第一个值为e的元素序号
    int getNo(T e);

    //在线性表值序号为i的位置插入元素e
    bool insert(int i,T e);

    //删除序号为i的元素
    bool remove(int i);

    //输出元素
    void dispList();

    //删除不为x的元素，时间复杂度O(n),空间复杂度o(1)
    void removeNo(SqList<T>&L,T x);

    //二路归并算法
    void merge(SqList<T> A,SqList<T>B,SqList<T>&C);

    //构造函数
    SqList();

    //初始化复制构造函数
    SqList(SqList<T>& A);

    //析构函数
    ~SqList();
};


#endif //CPP_SQLIST_H
