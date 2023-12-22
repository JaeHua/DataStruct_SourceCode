//
// Created by ������ on 2023/10/24.
//

#include <iostream>
#include <string>
using namespace std;
int nxt[1005];
int nxtVal[1005];
/**
 * KMP�㷨����BF�㷨�Ļ������������˻��ݣ������ƥ������.���Ӷ�O(n+m)
 * */
 void getNext(string t)
{
     nxt[0] = -1;
     int i = 0, j = -1; //i�ǵ�ǰ��������ƥ����ַ�λ��,Ҳ��next���������
     while(i < t.length() - 1)
     {
         if(j == -1 || t[j] == t[i])nxt[++i] = ++j;
         else j = nxt[j];
     }
}
void getNextVal(string t)
{
     nxtVal[0] = -1;
     int i = 0, j = -1;
     while(i < t.length() - 1)
     {
         if(j == -1 || t[j] == t[i])
         {
             i++;j++;
             if(t[i]!=t[j])
                 nxtVal[i] = j;
             else
                 nxtVal[i] = nxtVal[j];
         }
         else
             j = nxtVal[j];
     }
}
bool KMP(string s,string t)//sΪĿ�괮��t��ģʽ��
{
    getNext(t);
    int i = 0, j = 0;
    while(i < s.length() && j < t.length())
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j]; //i�����ݣ�j���˵�ʧ��ת�ƴ�
        }
    }
    return j==t.length() ;

}
int main(){
    while(1) {
        string s, t;
        cin >> s >> t;
        if (KMP(s, t))cout << t << " is " <<"the substring of "<< s <<"!" << endl;
        else
            cout << t << " isn't the substring of " << s << "!" << endl;
    }
    return 0;
}