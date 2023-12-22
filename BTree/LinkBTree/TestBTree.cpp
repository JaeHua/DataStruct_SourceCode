#include "BTree.cpp"
#include <iostream>
//由中序遍历与先序遍历得到树
BTNode*CreateBTree1(string pres,int i,string ins,int j,int n)
{
    if(n<=0)return nullptr;
    char d = pres[i];//根结点
    BTNode*b = new BTNode(d);
    int p = j;
    while (ins[p]!=d)p++;//在ins中找到根结点的索引
    int k = p - j;//确定左子树的结点个数k
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
    //参数 l1:左子树先序遍历起点;r1左子树先序遍历终点;l2:右子树先序遍历起点;r2:右子树先序遍历终点
    //创建根结点
    BTNode*root = new BTNode(pres[l1]);//先序遍历第一个结点必为根结点，取出根结点数据
    //找到根结点在中序遍历中的位置
    int i = l2;//记录根结点在中序遍历中的位置
    while(ins[i]!=root->data)i++;
    //此时i指向中序序列中的根结点
    int Llen = i - l2;//计算左子树元素个数
    int Rlen = r2 - i;//计算右子树元素个数

    if(Llen<=0)root->lchild = nullptr;//左子树为空
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
    // 创建二叉树"A(B(D,E),C)"
    tree.CreateBTree(s);

    // 输出二叉树
    cout << "构建的二叉树为:" << endl;
    tree.DispBTree();
    cout<<endl;
    // 前序遍历
    cout << "前序遍历:";
    tree.preOrder(tree.root);
    cout<<endl;
    // 中序遍历
    cout << "中序遍历:";
    tree.midOrder(tree.root);
    cout<<endl;
    // 后序遍历
    cout << "后序遍历:" ;
    tree.postOrder(tree.root);
    cout<<endl;
    //层次遍历
    cout<<"层次遍历:";
    tree.levelOrder(tree.root);
    cout<<endl;
    // 查找节点
    BTNode* node = tree.FindNode('E');
    if(node != nullptr) {
        cout << "找到节点:" << node->data << endl;
    } else {
        cout << "未找到节点" << endl;
    }

    // 获取树的高度
    int height = tree.Height();
    cout << "树的高度为:" << height << endl;

    //获取树的结点个数
    int nodeCount = tree.NodeCount();
    cout<<"树的结点个数为:"<<nodeCount<<endl;


    //从左到右获取树的叶子结点A(B(D,E),C)

    cout<<"从左到右叶子结点:";
    tree.DispLeaf();
    cout<<endl;
    //查找某个结点所在层次
    int h = tree.Level('E');
    cout<<"结点E在所在的高度为:"<<h<<endl;

    //某层的结点个数
    int knodenum = tree.Kcount(2);
    cout<<"第二层的结点个数是:"<<knodenum<<endl;

    //解x结点的所有祖先
    tree.Anscestor('E');

    //序列化树，空孩子用#代替
    string tr = tree.PreOrderSeq(tree.root);
    cout<<"树的序列化为:";
    cout<<tr<<endl;

    //反序列化
    cout<<"树的反序列化为:";
    BTree btt;
    btt.ReversePreOrderSeq(btt,tr);
    btt.levelOrder(btt.root);
    cout<<endl;
    //树左右子树进行交换
    tree.Swap();
    cout<<"左右子树交换后的先序遍历:";
    tree.preOrder2(tree.root);

    //由先序与中序得到树
    BTree bt;
    CreateBTreeByPreAndInOrder(bt,"ABDEC","DBEAC");
    cout<<"构成树为:";
    bt.levelOrder(bt.root);
    return 0;
}