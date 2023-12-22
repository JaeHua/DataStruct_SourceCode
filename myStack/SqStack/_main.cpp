//
// Created by ���� on 2023/9/28.
//
#include "SqStack.cpp"
#include <string>
#include <iostream>
#include <stack>
using  namespace std;
//�������ƥ������
bool isMatch(string str)
{
    SqStack<char>st;
    char e;
    int len = str.length();
    int i = 0;
    while(i < len)
    {
        //"("��ջ
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
//�����ַ�����
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
        cin >> len;  //����𳵳���


        stack<int> station;
        for (i = 0; i < len; ++i)    //�����Bվ�ĳ���˳��
        {
            cin >> Barr[i];

        }

        for (i = 1, j = 0; i <= len; ++i)    //��1-N�ĳ�����в���
        {
            while (!station.empty() && station.top() == Barr[j]) //��תվ��ջ����Ϊ���򣬱Ƚ�ջ����B�ĳ���ĺ���
            {
                station.pop();  //��ȵĻ��������ջ
                j++;    //���ԱȽ���һ�����������
            }
            station.push(i);    //ջΪ�ջ���ջ���������Ҫ��Ĳ��ȣ���ֱ�Ӱ�Aվ�ĳ�ѹ��ջ��
        }
        while (!station.empty() && station.top() == Barr[j]) //��1-N��ѹջ���ˣ�ջ�ڻ��г���Ļ���˳�κ�ջ���Ƚ�
        {
            station.pop();
            j++;
        }
        if (station.empty()) //���ջ��Ϊ���򣬿���ƥ��Ҫ���˳��
            cout << "Yes" << endl;
        else
            cout << "No" << endl;




}
int main()
{
    //����ƥ������:
//    cout<<"�����ַ���:"<<endl;
//    string str;
//    cin>>str;
//    bool flag = isMatch(str);
//    if(flag)cout<<"ƥ��ɹ�!"<<endl;
//    else cout<<"ƥ��ʧ��!"<<endl;

    //�����ַ�����
//    cout<<"�����ַ���:"<<endl;
//    string str;
//    cin>>str;
//    bool flag = isPalindrome(str);
//    if(flag)cout<<"�ǻ��Ĵ�!"<<endl;
//    else cout<<"���ǻ��Ĵ�!"<<endl;
    POJ1363();
    return 0;
}