//
// Created by ������ on 2023/10/24.
//
#include <iostream>
#include <string>
using namespace std;
/**
 * BF�㷨����Brute-Force�㷨����Ʊ����㷨.���Ӷ�O(n*m)n,m�ֱ�ΪĿ�괮��ģʽ���ĳ���
 * */
bool BF(string s,string t)//sΪĿ�괮��t��ģʽ��
{
    int i = 0,j = 0;
    while(i<s.length()&&j<t.length())//����δ������ʱѭ��
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        else//�Ƚϵ������ַ�����ͬʱ
        {
            i = i - j + 1;//���˵�s�ı��˿�ʼ����һ���ַ�,jΪʧ�䴦
            j = 0;  //j�ƶ���t����ͷ
        }


    }
    if(j >= t.length())return true;
    else   return false;
}
int main(){
    while(1) {
        string s, t;
        cin >> s >> t;
        if (BF(s, t))cout << t << "��" << s << "���Ӵ�!" << endl;
        else
            cout << t << "����" << s << "���Ӵ�!" << endl;
    }
    return 0;
}