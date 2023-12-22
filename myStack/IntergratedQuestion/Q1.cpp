//
// Created by 姜杰铧 on 2023/10/20.
//
/**问题描述】

现有一个以英文字母组成的字符序列，序列的元素个数为N（3<N<26），该序列通过一个顺序栈可以得到多种出栈序列，
 设计一个算法判断输入的序列str是否为一个合适的出栈序列。
【输入形式】

第一行输入序列的元素个数N（3<N<26）

第二行按顺序输入该序列的所有元素，输入顺序即为进栈的顺序

第三行输入一个不知道是否正确的出栈序列
【输出形式】
判断第三行输入的是否为可能的出栈序列，如果是则输出true，如果不是则输出false。*/
#include<stack>
#include <iostream>
using namespace std;
int n;
stack<char>st;
char a[30];
char b[30];
void solve(char b[],char a[],int n)
{
    int i,j;
    for( i = 0 ,j = 0; i < n; i ++)
    {

        while(!st.empty()&&st.top() == a[j])
        {

            st.pop();
            j++;
        }
        //对输入序列进行操作
        st.push(b[i]);
//        cout<<"st.top() = "<<st.top()<<endl;
    }
    //把剩下的进行判断
    while(!st.empty()&&st.top() == a[j])
    {
        st.pop();
        j++;
    }
    if(st.empty())
        cout<<"true";
    else
        cout<<"false";
}
int main(){
    //数据输入
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    for(int i = 0; i < n; i++)
        cin>>a[i];
    solve(b,a,n);
    return 0;
}