//
// Created by jjh on 2024/1/2.
//
#include<bits/stdc++.h>
using namespace std;
string s;
string postexp;
void transs()

{
    stack<char>op;
    int n = s.length();
    int i = 0;
    while(i<n)
    {
        int ch =s[i];
        if(ch == '(')op.push(ch);
        else if(ch == ')')
        {
            while (!op.empty()&&op.top()!='(')
            {
                postexp+=op.top();
                op.pop();
            }
            op.pop();//pop '('
        }
        else if(ch == '+' || ch =='-')
        {
            while(!op.empty()&&op.top()!='(')
            {
                postexp+=op.top();
                op.pop();
            }
            op.push(ch);
        }
        else if(ch == '*'||ch == '/')
        {
            while (!op.empty()&&(op.top() == '*'||op.top() =='/'))
            {
                postexp+=op.top();
                op.pop();
            }
            op.push(ch);
        }
        else
        {
            string d = "";
            while(ch >= '0'&&ch<='9')
            {
                d += ch;
                i++;
                ch = s[i];
            }
            i--;
            postexp+=d;
            postexp+='#';
        }
        i++;
    }
    //剩下的别忘记了！！！
    while(!op.empty())
    {
        postexp+=op.top();
        op.pop();
    }
}
int cacl(string exp)
{
    stack<int>num;
    int n = exp.size();
    int i = 0;
    while(i<n)
    {
        char ch = exp[i];
        if(ch == '+')
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(b+a);
        }
        else   if(ch == '-')
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(b-a);
        }
        else     if(ch == '*')
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(b*a);
        }
        else     if(ch == '/')
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(b/a);
        }
        else
        {
            int d = 0;
            while(ch>='0'&&ch<='9')
            {
                d = 10*d+(ch-'0');
                i++;
                ch=exp[i];
            }
            //i--不需要这个，因为要跳过'#'
            num.push(d);
        }
        i++;
    }
    return num.top();
}
int main(){
    cin>>s;
    transs();
    cout<<postexp<<endl;
    cout<<s<<"="<<cacl(postexp)<<endl;
    return 0;
}