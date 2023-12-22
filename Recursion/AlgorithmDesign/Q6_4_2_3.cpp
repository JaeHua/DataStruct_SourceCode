//
// Created by 姜杰铧 on 2023/11/10.
//
/*递归求解字符串t 在 字符串s中的出现次数*/
#include <iostream>
#include <string>
using namespace std;
int find_occur(string s,string t)
{
    if(s.length() < t.length())
        return 0;
    else
    {
        if(s.substr(0,t.length()) ==  t)
            return 1 + find_occur(s.substr(1),t);
        else
            return find_occur(s.substr(1),t);
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<find_occur(s,t)<<endl;
    return 0;
}