#include <iostream>
#include <fstream>
#include <map>
using namespace std;
string s[1005];
map<char,string>mp;
int n,m = 0;
void init()
{

    cin>>n;
    string ss;
    cin.ignore();
    for(int i= 0; i < n;i++)
    { getline(cin,ss);
        if(ss.empty())//去除空行
            continue;
        s[m++] = ss;
    }
//    for(int i = 0; i < m;i++)
//        cout<<s[i]<<endl;
}
void pre()
{
    for(int i = 0; i < m;i++)
        mp[s[i][0]] = s[i].substr(2);
}
//map<char, string>::iterator myFind(string st)
//{
//    map<char,string >::iterator it;
//    it = mp.begin();
//    while(it->second!=st&&it!=mp.end())
//        it++;
//    return it;
//}
void check()
{
    string str;
    ifstream ifs("in.txt");
    ifs>>str;
    string decoded = ""; // 解码
    string curCode = "";   // 当前编码


    for (char ch : str)
    {
        curCode += ch;


        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second == curCode)
            {
                decoded += it->first;
                curCode = "";
                break;
            }
        }
    }


    cout << decoded;
}
int main()
{
    init();
    pre();
    check();
    cout<<'\n';
    return 0;
}
/*
6
1:111
2:0
+:110
*:1010
=:1011
8:100
*/