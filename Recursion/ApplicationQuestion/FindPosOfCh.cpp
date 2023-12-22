//
// Created by 姜杰铧 on 2023/11/10.
//
/*
 * 题意:找到字符串t在s中出现的所有位置，不包括重叠的位置
 * */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int>ans;
int index = 0;
void findcha(string s,string t)
{

    if(t.length() > s.length())
        return;
    else
    {
        if(s.substr(0,t.length()) == t) {
            ans.push_back(index);
            index+=t.length();
            findcha(s.substr(t.length()),t);
        }
        else {
            index++;
            findcha(s.substr(1),t);
        }
    }
}
int main(){
    findcha("aababbabdbabababbdaababadaba","aba");
    for(auto it : ans)
        cout<<it<<" ";

    return 0;
}