//
// Created by jjh on 2023/11/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int>a;
void init(string s)
{
    int len = s.length();
//    cout<<s<<endl;
    bool fla = false;
    for(int i = 1; i < len - 1;i++)
    {
        string ss = "";
        bool flag = false;
        if(s[i]=='-')
        {
            fla = true;
        }
        while(s[i]>='0'&&s[i]<='9')
        {
            ss += s[i];
            i++;
            flag = true;
        }
        if(flag)
            if(fla) { a.push_back(-1 * stoi(ss));fla = false; }
            else
                a.push_back(stoi(ss));
        if(s[i] == 'n') { a.push_back(-1);i+=3; }

    }
}
void build(TreeNode*&b,int i)
{
    if(i>=a.size())
    {
        b = nullptr;
        return;
    }
    if(a[i] == -1)
    {
        b = nullptr;
        return;
    }

    b = new TreeNode(a[i]);
    build(b->left,2*i+1);
    build(b->right,2*i+2);
}
//void preOrder(TreeNode*b)
//{
//    if(b!= nullptr)
//    {
//        cout<<b->val<<" ";
//        preOrder(b->left);
//        preOrder(b->right);
//    }
//}
//void inOrder(TreeNode*b)
//{
//    if(b!= nullptr)
//    {
//        inOrder(b->left);
//        cout<<b->val<<" ";
//        inOrder(b->right);
//    }
//}
//void postOrder(TreeNode*b)
//{
//    if(b!= nullptr)
//    {
//        postOrder(b->left);
//        postOrder(b->right);
//        cout<<b->val<<" ";
//    }
//}
vector<int> b(15);
void getWideth(TreeNode*bt,int h)
{
    if(bt == nullptr)return;
    b[h]++;
    if(bt->left!= nullptr)getWideth(bt->left,h+1);
    if(bt->right!= nullptr)getWideth(bt->right,h+1);

}
int main()
{
   string s;
    getline(cin,s);

   init(s);
//   for(int i = 0; i < a.size();i++)
//       cout<<a[i]<<" ";
    TreeNode*bt;
    build(bt,0);
//    preOrder(bt);
//    cout<<endl;
//    inOrder(bt);
//    cout<<endl;
//    postOrder(bt);
//    cout<<endl;
    getWideth(bt,1);
    cout<<*max_element(b.begin(),b.end());
    return 0;
}