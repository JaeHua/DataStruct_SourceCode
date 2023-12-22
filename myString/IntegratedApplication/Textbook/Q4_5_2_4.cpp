//
// Created by 姜杰铧 on 2023/10/26.
//
/**如果串中一个长度大于1的子串的全部字符相同,则称之为等值子串。
 * 设计一个算法,求顺序串s中的一个长度最大的等值子串z,如果串s中不存在等值子串,则r为空串。*/

#include <iostream>
#include<string>
using namespace std;
string str;
char ch;
int len;
string solve(string str)
{
    //滑动窗口
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