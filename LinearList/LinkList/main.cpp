//
// Created by ������ on 2023/9/22.
//
#include "LinkList.h"
#include "LinkList.cpp"
int main(){
    //����������
    LinkList<int>myList;
    int a[] = {1,3,5,7,9};
    //β�巨����
    myList.createListR(a,5);
    myList.dispList();

    //��ȡ���Ϊ2��Ԫ��
    int e;
    myList.getElem(2,e);
    cout<<"Element 2 is :"<<e<<endl;

    //�޸����Ϊ3��Ԫ��Ϊ8
    myList.setElem(3,8);
    cout<<"after modify:"<<endl;
    myList.dispList()  ;

    //����Ԫ��5��λ��
    int pos = myList.getNo(5);
    cout<<"Element 5 is :"<<pos<<endl;


    //�ڵ�����λ�ò���4
    myList.insert(2,4);
    myList.dispList();

    //ɾ����1���λ��
    myList.remove(1);
    myList.dispList();

    //��ת����
    myList.reverse();
    myList.dispList();
    return 0;
}