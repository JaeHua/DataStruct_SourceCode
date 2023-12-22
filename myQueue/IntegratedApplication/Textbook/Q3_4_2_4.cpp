//
// Created by 姜杰铧 on 2023/10/18.
//
/**
 4.用于列车编组的铁路转轨网络是一种栈结构,如图3.32所示。其中,右边轨道是输人端,
 左边轨道是输出端。当右边轨道上的车皮编号顺序为1、2、3、4时,
 如果执行操作进栈、进栈、出栈、进栈、进栈、出栈、出栈、出栈,则在左边轨道上的车皮编号顺序为2、4,3、1
 设计一个算法,给定n个整数序列a表示右边轨道上的车皮编号顺序,用上述转轨栈对这些车皮重新编号,
 使得编号为奇数的车皮都排在编号为偶数的车皮的前面,要求产生所有操作的字符串op和最终结果字符串ans。
 */
#include <stack>
#include <iostream>
using namespace std;
int a[1005];//用来存放序列
stack<int>stk;
stack<int>ans;
int n;
string s[] = {"PUSH","POP"};
string solve()
{
    for(int i = 0 ; i < n; i++)
    {
        if(a[i]&1)
        {
            cout<<s[0]<<" "<<s[1]<<" ";
            ans.push(a[i]);
        }
        else
        {
            cout<<s[0]<<" ";
            stk.push(a[i]);
        }
    }
    while(!stk.empty())
    {
        cout<<s[0]<<" ";
        ans.push(stk.top());
        stk.pop();
    }
    string s = "";
    while(!ans.empty())
    {
        string  tmp = to_string(ans.top());
        ans.pop();
        s = tmp[0] + s;
    }
    return s;
}
int main(){
    cout<<"Enter the number:"<<endl;
    cin>>n;
    cout<<"Enter the squence:"<<endl;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    string ans = solve();
    cout<<"\n";
    cout<<ans<<endl;
    return 0;
}