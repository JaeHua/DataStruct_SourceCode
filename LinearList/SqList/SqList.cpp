//
// Created by 姜杰铧 on 2023/9/22.
//

#include "SqList.h"
#include <iostream>
template<typename T>
void SqList<T>::recap(int newcap) {
    if(newcap<=0)return;    //容量不能为0
    T*odddata = data;       //保存原来的空间
    data = new T[newcap];   //申请新空间
    for(int i=0;i<length;i++) {     //复制
        data[i] = odddata[i];
    }
    delete[] odddata;   //释放原来的空间
}
template<typename T>
void SqList<T>::creatList(T a[],int n) {
    for(int i = 0; i<=n;i++) {
        if(length == capacity)
            recap(2*capacity);
        data[length++] = a[i];
    }
}
template<typename T>
void SqList<T>::add(T e) {
    if(length==capacity) {
        recap(2*capacity);
    }
    data[length++] = e;
}
template<typename T>
int SqList<T>::getLength() {
    return length;
}
template<typename T>
bool SqList<T>::getElem(int i,T& e) {
    if(i<0||i>=length)return false;         //序号不合法
    e = data[i];
    return true;
}
template<typename T>
bool SqList<T>::setElem(int i,T e) {
    if(i<0||i>=length)return false;     //序号不合法
    data[i] = e;
    return true;
}
template<typename T>
int SqList<T>::getNo(T e) {
    for(int i=0;i<length;i++) {
        if(data[i]==e) {
            return i;
        }
    }
    return -1;
}
template<typename T>
bool SqList<T>::insert(int i,T e) {
    if (i < 0 || i > length)return false;   //插入位置不合法
    if (length == capacity) {                 //顺序表已满
        recap(2 * capacity);
    }
    for (int j = length; j > i; j--)        //后移
        data[j] = data[j - 1];
    data[i] = e;
    length++;
    return true;
}
template<typename T>
bool SqList<T>::remove(int i) {
    if (i < 0 || i >= length)return false;
    for (int j = i; j < length - 1; j++)
        data[j] = data[j + 1];         //后移
    length--;
    if(capacity>initcap&&length<=capacity/4) {
        recap(capacity/2);         //缩小容量
    }
}
template<typename T>
void SqList<T>::dispList() {
    for (int i = 0; i < length; i++)
        cout << data[i] << " ";
    cout << endl;
}
template<typename T>
//删除不为x的元素，时间复杂度O(n),空间复杂度o(1)
void SqList<T>::removeNo(SqList<T>&L,T x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (data[i] != x) {
            data[k++] = data[i];         //复制到k中
        }
    }
}
template<typename T>
void SqList<T>::merge(SqList<T> A, SqList<T> B,SqList<T>&C) {
    int i = 0,j = 0; //i指向A,j指向B
    while (i < A.length && j < B.length) {  //合并
        if (A.data[i] < B.data[j]) {
            C.add(A.data[i++]);        //添加到C
        }else
            C.add(B.data[j++]);        //添加到C
    }
    while (i < A.length) {           //添加剩余
        C.add(A.data[i++]);
    }
    while (j < B.length) {
        C.add(B.data[j++]);
    }
}
template<typename T>
SqList<T>::SqList() {
    data = new T[initcap];
    length = 0;
    capacity = initcap;
}
template<typename T>
SqList<T>::SqList(SqList<T> &A) {
    capacity = A.capacity;  //复制容量
    length = A.length;      //复制长度
    data = new T[capacity];
    for(int i = 0;i<length;i++) {
        data[i] = A.data[i];
    }
}
template<typename T>
SqList<T>::~SqList() {
    delete[] data;
}