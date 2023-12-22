//
// Created by 刘禧 on 2023/9/28.
//
#include "SqStack.cpp"
#include <string>
#include <iostream>
#include <stack>
using  namespace std;
//解决括号匹配问题
bool isMatch(string str)
{
    SqStack<char>st;
    char e;
    int len = str.length();
    int i = 0;
    while(i < len)
    {
        //"("入栈
        if(str[i] == '(' || str[i] == '['||str[i] =='{')
        {
            st.push(str[i]);
        }
        else
        {
            if(str[i] == ')')
            {
                if(st.empty())return false;
                st.pop(e);
                if(e!='(')return false;
            }
            if(str[i] == ']')
            {
                if(st.empty())return false;
                st.pop(e);
                if(e!='[')return false;
            }
            if(str[i] == '}')
            {
                if(st.empty())return false;
                st.pop(e);
                if(e!='{')return false;
            }
        }
        i++;
    }
    return st.empty();
}
//回文字符问题
bool isPalindrome(string str)
{
    SqStack<char>st;
    char e;
    int len = str.length();
    int i = 0,j = 0;
    while(i<len)
    {
        st.push(str[i]);
        i++;
    }
    while(!st.empty())
    {
        st.pop(e);
        if(e != str[j])
            return false;
        j++;
    }
    return true;
}
void POJ1363()
{

        int Barr[1005], i = 0, j = 0, len;
        cin >> len;  //输入火车长度


        stack<int> station;
        for (i = 0; i < len; ++i)    //输入火车B站的车厢顺序
        {
            cin >> Barr[i];

        }

        for (i = 1, j = 0; i <= len; ++i)    //对1-N的车厢进行操作
        {
            while (!station.empty() && station.top() == Barr[j]) //中转站（栈）不为空则，比较栈顶与B的车厢的号码
            {
                station.pop();  //相等的话，车厢出栈
                j++;    //可以比较下一个车厢号码了
            }
            station.push(i);    //栈为空或者栈顶车厢号与要求的不等，则直接把A站的车压入栈内
        }
        while (!station.empty() && station.top() == Barr[j]) //当1-N都压栈完了，栈内还有车厢的话，顺次和栈顶比较
        {
            station.pop();
            j++;
        }
        if (station.empty()) //最后栈内为空则，可以匹配要求的顺序
            cout << "Yes" << endl;
        else
            cout << "No" << endl;




}
int main()
{
    //括号匹配问题:
//    cout<<"输入字符串:"<<endl;
//    string str;
//    cin>>str;
//    bool flag = isMatch(str);
//    if(flag)cout<<"匹配成功!"<<endl;
//    else cout<<"匹配失败!"<<endl;

    //回文字符问题
//    cout<<"输入字符串:"<<endl;
//    string str;
//    cin>>str;
//    bool flag = isPalindrome(str);
//    if(flag)cout<<"是回文串!"<<endl;
//    else cout<<"不是回文串!"<<endl;
    POJ1363();
    return 0;
}