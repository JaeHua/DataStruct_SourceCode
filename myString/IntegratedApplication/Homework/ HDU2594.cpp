//
// Created by jjh on 2023/11/12.
//
#include<iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
int getNext(string s,int n,int m)
{
//    cout<<s<<endl;
    int nxt[100005];
    memset(nxt,0,sizeof(nxt));
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < s.length()-1)
    {
        if(j == -1 || s[i] == s[j])
        {
            j++;i++;
            nxt[i] = j;
        }
        else j = nxt[j];
    }

//    cout<<s.length()<<endl;
    return nxt[s.length()-1];
}
int main(){
    ifstream  ifs;
    ifs.open("in.txt");
    string s1,s2;
    ifs>>s1>>s2;
    int n1 = s1.length();
    int n2 = s2.length();
    string s3 = s1 + s2 +"1";
//    cout<<s3<<endl;
//    cout<<s3.length()<<endl;
    int ret = getNext(s3,n1,n2);
    if(ret == 0)cout<<0<<endl;
    else
    {
        cout<<s1.substr(0,ret)<<" "<<(ret>n1?n1:ret)<<endl;
    }
    ifs.close();
    return 0;
}