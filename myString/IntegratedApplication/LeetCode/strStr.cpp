//
// Created by ½ª½Üîü on 2023/10/27.
//
#include <bits/stdc++.h>
using namespace std;

    void getNext(string t,int *nextval)
    {
        int j = 0,k = -1;
        nextval[0] = -1;
        while(j<t.length() -1)
        {
            if(k == -1 || t[j] == t[k])
            {
                j++;
                k++;
                if(t[j]!=t[k])
                    nextval[j] =k;
                else
                    nextval[j] = nextval[k];
            }
            else
                k = nextval[k];
        }
        for (int i = 0; i < 5; ++i) {
            cout<<nextval[i]<<" ";
        }
    }
    int KMP(string s,string t)
    {
        int n = s.length(),m = t.length();
        int *nextval = new int[m];
        getNext(t,nextval);
        int i = 0,j = 0;
        while(i<n&&j<m)
        {
            if(j == -1||s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j = nextval[j];

        }
        if(j >= m)return i - m;
        else return -1;
    }
    int strStr(string haystack, string needle) {
        return KMP(haystack,needle);
    }

int main(){

    cout<<strStr("mississippi","issip");

    return 0;
}