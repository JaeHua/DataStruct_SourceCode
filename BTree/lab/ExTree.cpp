//
// Created by jjh on 2023/11/29.
//
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;
stack <int> da;//数据存储栈
stack<char>op;//操作符辅助栈
struct node
{
    string data;
    node*left;
    node*right;
    //无参构造,不能省
    node(){left = nullptr;right = nullptr;}
    //有参构造
    node(string d):data(d),left(nullptr),right(nullptr){};
};
//中缀表达式转为后缀表达式
string trans(string s)
{
    string ret = "";
    int i = 0;
    char ch;
    while(i < s.length())
    {
        ch = s[i];
        if(ch == '(')
            op.push(ch);
        else if(ch == ')')
        {
            while(op.top()!='(')
            {
                ret += op.top();
                op.pop();
            }
            op.pop();//弹出'('
        }
        else if(ch == '+' || ch == '-')
        {
            while(!op.empty()&&op.top()!='(')
            {
                ret += op.top();
                op.pop();
            }
            op.push(ch);
        }
        else if(ch == '*' || ch == '/')
        {
            while (!op.empty() &&(op.top() == '/'||op.top() == '*'))
            {
                ret += op.top();
                op.pop();
            }
            op.push(ch);
        }else if(ch == '=')break;
        else
        {
            string d = "";
            while(ch >= '0'&&ch<='9')
            {
                d += ch;
                i++;
                if(i < s.length())
                    ch = s[i];
                else
                    break;

            }
            i--;
            ret += d;
            ret +='#';
        }
        i++;
    }
    //剩下的全部出栈
    while(!op.empty()) { ret += op.top();op.pop(); }
    return ret;
}
void build(string s,node*&bt)
{
    int i = 0;
    stack<node*>st;
    while(i < s.length())
    {
        char ch = s[i];

        if(ch == '+' || ch == '-' || ch == '*' || ch =='/')
        {
            string da = "";
            da += ch;
            node *root = new node(da);
            node* s1 = st.top();st.pop();
            node* s2 = st.top();st.pop();
            //顺序别搞反了
            root->left = s2;
            root->right = s1;
            st.push(root);
        }else {
            string d = "";
            while (ch >= '0' && ch <= '9') {
                d += ch;
                i++;
                if (i < s.length())
                    ch = s[i];
                else
                    break;
                if (s[i] == '#')break;
            }
            node *rt = new node(d);
            st.push(rt);
        }
        i++;
    }
    bt = st.top();
//    cout<<bt->left->data<<endl;
//    cout<<"Success!"<<endl;
}
void preOrder(node*bt)
{
    if(bt!= nullptr)
    {
        if(bt->data[0]<='9'&&bt->data[0]>='0')
        {
            cout<<bt->data<<'#';
        }
        else cout<<bt->data;
        preOrder(bt->left);
        preOrder(bt->right);
    }
}
void inOrder(node*bt)
{
    if(bt!= nullptr)
    {
        inOrder(bt->left);
        if(bt->data[0]<='9'&&bt->data[0]>='0')
        {
            cout<<bt->data<<'#';
        }
        else cout<<bt->data;
        inOrder(bt->right);
    }
}
void postOrder(node*bt)
{
    if(bt!= nullptr)
    {
        postOrder(bt->left);
        postOrder(bt->right);
        if(bt->data[0]<='9'&&bt->data[0]>='0')
        {
            cout<<bt->data<<'#';
        }
        else cout<<bt->data;
    }
}
void levelOrder(node*bt)
{
    queue<node*>qu;
    if(bt == nullptr)return;
    qu.push(bt);
    while(!qu.empty())
    {
        int n = qu.size();
        for(int i = 0; i < n;i++)
        {
            node*x = qu.front();qu.pop();
            if(x->data[0]>='0'&&x->data[0]<='9')
            {
                cout<<x->data<<'#';
            }else cout<<x->data;
            if(x->left!= nullptr)
                qu.push(x->left);
            if(x->right!= nullptr)
                qu.push(x->right);
        }
    }
}
int cacul(node*bt)
{
    string st = bt->data;
    if(st == "+")return cacul(bt->left) + cacul(bt->right);
    else if(st == "-")return cacul(bt->left) - cacul(bt->right);
    else if(st == "*")return cacul(bt->left) * cacul(bt->right);
    else if(st == "/")return cacul(bt->left) / cacul(bt->right);
    else
    {
        int d = 0;
        //数字串转为整数
         stringstream geek(st);
         geek>>d;
         return d;

    }
}
int main()
{
    node *bt;
    string str;
    cin>>str;
    str = trans(str);
    build(str,bt);
//  cout<<bt->data<<endl;
    preOrder(bt);
    cout<<'\n';
    inOrder(bt);
    cout<<'\n';
    postOrder(bt);
    cout<<'\n';
    levelOrder(bt);
    cout<<'\n';
    cout<<cacul(bt)<<endl;
    return 0;
}