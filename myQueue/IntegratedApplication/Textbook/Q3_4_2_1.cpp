//
// Created by ������ on 2023/10/18.
//
/**1.����һ���ַ���str,���һ���㷨,����˳��ջ�ж�sr�Ƿ�Ϊ���硰����1@����2��
 * �ĺϷ��ַ���,��������2������1������,��str��ǡ��ֻ��һ��@�ַ���*/

#include<stack>
#include <iostream>
#include <string>
using namespace std;
string s;
bool solve(string str)
{
    //����
    if(!str.length()&1)return false;
    stack<char>st;
    int i = 0;
    while(i < str.length()/2)
    {
        //ֻ�����м���Ψһһ��'@'
        if(str[i] == '@')
            return false;
        st.push(str[i]);
        i++;
    }
    if(str[i]!='@')return false;//�ж��м�Ϊ�ַ�'@'
    i++;//����@�ַ�
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
        cout << "����һ���ַ���:" << endl;
        cin >> s;
        if (!solve(s))
            cout << "Do not match !" << endl;
        else
            cout << "Matched!" << endl;
    }
    return 0;
}