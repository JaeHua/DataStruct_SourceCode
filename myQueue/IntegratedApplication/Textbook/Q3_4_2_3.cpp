//
// Created by ������ on 2023/10/18.
//
/**���һ���㷨������˳��ջ��һ��ʮ����������dת��Ϊr(2<=r=16��
 ���Ƶ�������Ҫ��r���������ַ���string��ʾ
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
char ch[6] = {'a','b','c','d','e','f'};
string convert(int r,int d)
{
    stack<char>stk;
    if(d == 0)
        return 0;
    while(d!=0)
    {
        int tmp = d%r;
        d /= r;
        if(tmp>9)
        {
           stk.push(ch[tmp - 10]);
        }else {
            //ֻ������ת��Clion�������Ų��������
            string s = to_string(tmp);
            stk.push(s[0]); }
    }
    string s = "";
    while(!stk.empty())
    {
        s = s + stk.top()  ;
        stk.pop();
    }
    return s;

}
int main()
{
    int r,d;
    cout<<"Enter the base you want to convert to :"<<endl;
    cin>>r;
    cout<<"Enter the number you want to convert :"<<endl;
    cin>>d;
    string ans = convert(r,d);
    int id = -1;
    for(int i = 0; i < ans.size()&&ans[i] < '1';i++)
    {
        if(ans[i] == '0')
            id = i;
    }
    //ע��ɾ��ǰ��0
    if(id==-1)
        cout<<d<<" to base r is :"<<ans<<endl;
    else
    {
        ans = ans.substr(id + 1,ans.size() - id - 1);
        cout<<d<<" to base r is :"<<ans<<endl;
    }


    return 0;
}