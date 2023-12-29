//
// Created by jjh on 2023/12/28.
//
#include <iostream>
using namespace std;
#define maxm 100
template <typename T>
struct HNode
{
    int key;//关键字
    T value;//数据值
    HNode<T>*next;
    HNode(){}
    HNode(int k,int v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};
template<typename T>

class HashTable
{
public:
    int n; //元素个数
    int m;//哈希表长度
    HNode<T>*ha[maxm];
    HashTable(int m)
    {
        this->m = m;
        for(int i = 0; i < m;i++)
            ha[i] = nullptr;
        n = 0;
    }
//    ~HashTable()
//    {
//        …………
//    }
    void insert(int k,T v)
    {
        int d = k % m;
        HNode<T>* p = new HNode<T>(k,v);
        p->next = ha[d];
        ha[d] = p;
        n++;
    }
    HNode<T>*search(int k)
    {
        int d = k % m;
        HNode<T>*p = ha[d];
        while (p!= nullptr&&p->key!=k)
            p = p->next;
        return p;
    }
};