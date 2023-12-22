//
// Created by 姜杰铧 on 2023/10/24.
//
#include <iostream>
#include <string>
using namespace std;
/**
 * BF算法，即Brute-Force算法，简称暴力算法.复杂度O(n*m)n,m分别为目标串和模式串的长度
 * */
bool BF(string s,string t)//s为目标串，t是模式串
{
    int i = 0,j = 0;
    while(i<s.length()&&j<t.length())//两串未遍历完时循环
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        else//比较的两个字符不相同时
        {
            i = i - j + 1;//回退到s的本趟开始的下一个字符,j为失配处
            j = 0;  //j移动到t串开头
        }


    }
    if(j >= t.length())return true;
    else   return false;
}
int main(){
    while(1) {
        string s, t;
        cin >> s >> t;
        if (BF(s, t))cout << t << "是" << s << "的子串!" << endl;
        else
            cout << t << "不是" << s << "的子串!" << endl;
    }
    return 0;
}