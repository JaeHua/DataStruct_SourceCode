//
// Created by ������ on 2023/9/22.
//
#include "SqList.h"
#include "SqList.cpp"
const int maxN = 1005;
int main() {

    //����SqList����
    SqList<int>myList;

    //����
    int cnt = 0;
    int arr[maxN];
    //��arr��ֵΪ0
    for(int i = 0; i < maxN;i++)
        arr[i] = 0;
   cout<<"�����������С:"<<endl;
   cin>>cnt;
   cout<<"����������Ԫ��:"<<endl;
   for(int i = 0; i < cnt;i++)
       cin>>arr[i];
   cnt--;
   myList.creatList(arr,cnt);

    //��ӡ˳���
    myList.dispList();

    //��β���Ԫ��
    myList.add(10);
    myList.dispList();

    //�����2��λ�ò���Ԫ��4
    myList.insert(2,4);
    myList.dispList();

    //ɾ�����3��Ԫ��
    myList.remove(3);
    myList.dispList();

    //��ȡ���1��Ԫ��
    int e;
    myList.getElem(1,e);
    myList.dispList();

    //ɾ��3Ԫ��
    myList.removeNo(myList,3);
    myList.dispList();
    cout<<"after merge:"<<endl;
    //��ʾ�鲢
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