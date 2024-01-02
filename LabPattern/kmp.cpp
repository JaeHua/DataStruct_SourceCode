//
// Created by jjh on 2024/1/2.
//
#include<iostream>
#include<string>
using namespace std;
int nxt[1005];
string s,t;
void getNext()
{
    int n = t.length();
    int j = 0, k = -1;
    nxt[0] = -1;
    while(j < n - 1)
    {
        if(k == -1 || t[j] == t[k])
            nxt[++j] = nxt[++k];
        else k = nxt[k];
    }
}
bool kmp(){
    int n = s.length(),m = t.length();
    getNext();
    int i = 0,j = 0;
    while(i<n&&j<m)
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = nxt[j];
    }
    if(j >= m-1)return true;
    else return false;
}
int main()
{

        cin >> s >> t;
        if (kmp()) {
            printf("%s is of %s\t", t.c_str(), s.c_str());
        } else printf("%s is not of %s\t", t.c_str(), s.c_str());
        cout<<endl;
//         int it = s.find(t);
//         if(it == string::npos)
//             cout<<"fail"<<endl;
//         else cout<<"ok"<<endl;
    return 0;
}