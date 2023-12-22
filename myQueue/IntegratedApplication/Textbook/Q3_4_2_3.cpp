//
// Created by 姜杰铧 on 2023/10/18.
//
/**设计一个算法，利用顺序栈将一个十进制正整数d转换为r(2<=r=16）
 进制的数，，要求r进制数用字符串string表示
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
            //只有这样转换Clion编译器才不会出问题
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
    //注意删除前导0
    if(id==-1)
        cout<<d<<" to base r is :"<<ans<<endl;
    else
    {
        ans = ans.substr(id + 1,ans.size() - id - 1);
        cout<<d<<" to base r is :"<<ans<<endl;
    }


    return 0;
}