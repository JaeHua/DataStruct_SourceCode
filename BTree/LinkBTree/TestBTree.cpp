#include "BTree.cpp"
#include <iostream>
//�������������������õ���
BTNode*CreateBTree1(string pres,int i,string ins,int j,int n)
{
    if(n<=0)return nullptr;
    char d = pres[i];//�����
    BTNode*b = new BTNode(d);
    int p = j;
    while (ins[p]!=d)p++;//��ins���ҵ�����������
    int k = p - j;//ȷ���������Ľ�����k
    b->lchild = CreateBTree1(pres,i+1,ins,j,k);
    b->rchild = CreateBTree1(pres,i+k+1,ins,p+1,n-k-1);
    return b;
}
BTNode*CreateBTree(BTree& bt,string pres,string ins)
{
    int n = pres.length();
    bt.root = CreateBTree1(pres,0,ins,0,n);
}
BTNode*CreateBTreeByPreAndInOrder1(string pres,int l1,int r1,string ins,int l2,int r2)
{
    //���� l1:����������������;r1��������������յ�;l2:����������������;r2:��������������յ�
    //���������
    BTNode*root = new BTNode(pres[l1]);//���������һ������Ϊ����㣬ȡ�����������
    //�ҵ����������������е�λ��
    int i = l2;//��¼���������������е�λ��
    while(ins[i]!=root->data)i++;
    //��ʱiָ�����������еĸ����
    int Llen = i - l2;//����������Ԫ�ظ���
    int Rlen = r2 - i;//����������Ԫ�ظ���

    if(Llen<=0)root->lchild = nullptr;//������Ϊ��
    else root->lchild = CreateBTreeByPreAndInOrder1(pres,l1+1,l1+Llen,ins,l2,i-1);

    if(Rlen<=0)root->rchild = nullptr;
    else root->rchild = CreateBTreeByPreAndInOrder1(pres,l1+Llen+1,r1,ins,i+1,r2);
    return root;
}
BTNode*CreateBTreeByPreAndInOrder(BTree& bt,string s1,string s2)
{
    int n = s1.length();
    bt.root = CreateBTreeByPreAndInOrder1(s1,0,n-1,s2,0,n-1);
}
int main() {

    BTree tree;
    string s;
    cin>>s;
    // ����������"A(B(D,E),C)"
    tree.CreateBTree(s);

    // ���������
    cout << "�����Ķ�����Ϊ:" << endl;
    tree.DispBTree();
    cout<<endl;
    // ǰ�����
    cout << "ǰ�����:";
    tree.preOrder(tree.root);
    cout<<endl;
    // �������
    cout << "�������:";
    tree.midOrder(tree.root);
    cout<<endl;
    // �������
    cout << "�������:" ;
    tree.postOrder(tree.root);
    cout<<endl;
    //��α���
    cout<<"��α���:";
    tree.levelOrder(tree.root);
    cout<<endl;
    // ���ҽڵ�
    BTNode* node = tree.FindNode('E');
    if(node != nullptr) {
        cout << "�ҵ��ڵ�:" << node->data << endl;
    } else {
        cout << "δ�ҵ��ڵ�" << endl;
    }

    // ��ȡ���ĸ߶�
    int height = tree.Height();
    cout << "���ĸ߶�Ϊ:" << height << endl;

    //��ȡ���Ľ�����
    int nodeCount = tree.NodeCount();
    cout<<"���Ľ�����Ϊ:"<<nodeCount<<endl;


    //�����һ�ȡ����Ҷ�ӽ��A(B(D,E),C)

    cout<<"������Ҷ�ӽ��:";
    tree.DispLeaf();
    cout<<endl;
    //����ĳ��������ڲ��
    int h = tree.Level('E');
    cout<<"���E�����ڵĸ߶�Ϊ:"<<h<<endl;

    //ĳ��Ľ�����
    int knodenum = tree.Kcount(2);
    cout<<"�ڶ���Ľ�������:"<<knodenum<<endl;

    //��x������������
    tree.Anscestor('E');

    //���л������պ�����#����
    string tr = tree.PreOrderSeq(tree.root);
    cout<<"�������л�Ϊ:";
    cout<<tr<<endl;

    //�����л�
    cout<<"���ķ����л�Ϊ:";
    BTree btt;
    btt.ReversePreOrderSeq(btt,tr);
    btt.levelOrder(btt.root);
    cout<<endl;
    //�������������н���
    tree.Swap();
    cout<<"����������������������:";
    tree.preOrder2(tree.root);

    //������������õ���
    BTree bt;
    CreateBTreeByPreAndInOrder(bt,"ABDEC","DBEAC");
    cout<<"������Ϊ:";
    bt.levelOrder(bt.root);
    return 0;
}