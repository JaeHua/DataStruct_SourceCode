//
// Created by ������ on 2023/10/26.
//
/**�������һ�����ȴ���1���Ӵ���ȫ���ַ���ͬ,���֮Ϊ��ֵ�Ӵ���
 * ���һ���㷨,��˳��s�е�һ���������ĵ�ֵ�Ӵ�z,�����s�в����ڵ�ֵ�Ӵ�,��rΪ�մ���*/

#include <iostream>
#include<string>
using namespace std;
string str;
char ch;
int len;
string solve(string str)
{
    //��������
    int n = str.length();
    int l = 0,r = 1;
    if(n <= 1)return str;
    ch = str[l];
    len = 1;
    while(l<n&&r<n)
    {
        while(str[l] == str[r]) {

            if(r - l + 1 > len)
            {
                len = r - l + 1;
                ch = str[l];
            }r++;
        }
        l = r;
        r = l + 1;
    }
    string ans = "";
    for(int i = 0; i < len ;i++)
    {
        ans += ch;
    }
    return ans;
}
int main(){
    cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}