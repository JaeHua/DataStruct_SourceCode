//
// Created by ������ on 2023/11/8.
//
#include <string>
#include <vector>

using namespace std;
#ifndef CPP_BTREE_H
#define CPP_BTREE_H
//�������������
struct  BTNode{
    char data;  //����Ԫ��
    BTNode*lchild;//���ӽ��
    BTNode*rchild;//���ӽ��
    BTNode():lchild(nullptr),rchild(nullptr){}//���캯��
    BTNode(char d){
        data = d;
        lchild = rchild = nullptr;  //���ع��캯��
    }
};

class BTree {

public:
    BTNode*root;//�����
    BTree(){root = nullptr;}//�������
    void CreateBTree(string str);//�����������洢�ṹ
    void DispBTree();//���ű�ʾ�����
    void DispBTree1(BTNode*b);//��DispBTree��������
    void preOrder(BTNode*b);
    void postOrder(BTNode*b);
    void midOrder(BTNode*b);
    void levelOrder(BTNode*b);
    BTNode*FindNode(char x);//����ĳ��ֵ
    BTNode*FindNode1(BTNode*b,char x);
    int Height();//��������߶�
    int Height1(BTNode*b);
    int NodeCount1(BTNode*b);//�������������
    int NodeCount2(BTNode*b);//ֱ�ӵݹ����
    int NodeCount();//���������������
    void DispLeaf1(BTNode*b);
    void DispLeaf();//���������Ҷ�ӽڵ�
    void DestoryBTree(BTNode*b);//�ͷ����пռ�
    void Swap1(BTNode*b);//����������������
    void Swap();
    int Level1(BTNode*b,char x,int h);//��ָ��������ڲ��
    int Level(char x);
    void Kcount1(BTNode*b,int h,int k,int &cnt);//���k��Ľ�����
    int Kcount(int k);
    void Anscestor1(BTNode*b,char x,vector<char>path,vector<char>&res);//���x����������
    void Anscestor(char x);
    void preOrder2(BTNode*b);//�ǵݹ�ʽ�������
    string PreOrderSeq(BTNode*b);//���������������
    BTNode* ReversePreOrderSeq1(string s,int &i);//������
    void ReversePreOrderSeq(BTree&bt,string s);
    BTNode* findSibling(struct BTNode* root, char x);//�ҵ����ֵΪx���ֵܽ��
    ~BTree()//�Զ�����
    {
        DestoryBTree(root);
        root = nullptr;
    }
};


#endif //CPP_BTREE_H
