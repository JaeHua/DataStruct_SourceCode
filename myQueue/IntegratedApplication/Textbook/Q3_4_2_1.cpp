//
// Created by 姜杰铧 on 2023/10/18.
//
/**1.给定一个字符串str,设计一个算法,采用顺序栈判断sr是否为形如“序列1@序列2”
 * 的合法字符串,其中序列2是序列1的逆序,在str中恰好只有一个@字符。*/

#include<stack>
#include <iostream>
#include <string>
using namespace std;
string s;
bool solve(string str)
{
    //特判
    if(!str.length()&1)return false;
    stack<char>st;
    int i = 0;
    while(i < str.length()/2)
    {
        //只允许中间有唯一一个'@'
        if(str[i] == '@')
            return false;
        st.push(str[i]);
        i++;
    }
    if(str[i]!='@')return false;//判断中间为字符'@'
    i++;//跳过@字符
    while(i<str.length())
    {
        if(str[i] == '@')
            return false;
        if(str[i++]!=st.top())
            return false;
        st.pop();
    }
    return true;
}
int main(){
    while(true) {
        cout << "输入一个字符串:" << endl;
        cin >> s;
        if (!solve(s))
            cout << "Do not match !" << endl;
        else
            cout << "Matched!" << endl;
    }
    return 0;
}