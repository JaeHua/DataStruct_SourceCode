//
// Created by ������ on 2023/9/22.
//

#ifndef CPP_SQLIST_H
#define CPP_SQLIST_H
using namespace std;
const int initcap = 5;      //˳���ĳ�ʼ����
template<typename T>
class SqList {
public:
    T*data;                  //���˳���ռ��ָ��
    int capacity;             //˳��������
    int length;               //˳���ĳ���
    //����
    void recap(int newcap);

    //����
    void creatList(T a[],int n);

    //��β���Ԫ��
    void add(T e);

    //��˳�����
    int getLength();

    //�����Ϊi��Ԫ��ֵ
    bool getElem(int i,T& e);

    //�������Ϊi��Ԫ��ֵ
    bool setElem(int i,T e);

    //���ҵ�һ��ֵΪe��Ԫ�����
    int getNo(T e);

    //�����Ա�ֵ���Ϊi��λ�ò���Ԫ��e
    bool insert(int i,T e);

    //ɾ�����Ϊi��Ԫ��
    bool remove(int i);

    //���Ԫ��
    void dispList();

    //ɾ����Ϊx��Ԫ�أ�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�o(1)
    void removeNo(SqList<T>&L,T x);

    //��·�鲢�㷨
    void merge(SqList<T> A,SqList<T>B,SqList<T>&C);

    //���캯��
    SqList();

    //��ʼ�����ƹ��캯��
    SqList(SqList<T>& A);

    //��������
    ~SqList();
};


#endif //CPP_SQLIST_H
