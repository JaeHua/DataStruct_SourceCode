//
// Created by ½ª½Üîü on 2023/10/27.
//
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
    vector<string>ans;
    string mp = "()";
    string s;
    bool is_valid(string st)
    {
        stack<char>stk;
        for(int i = 0; i < st.size();i++)
        {
            if(st[i] == '(')
                stk.push(st[i]);
            else
            {
                if(stk.empty())return false;
                if(stk.top() == '(')
                    stk.pop();
            }
        }
        return stk.empty();
    }
    void dfs(int pos,int n)
    {
        if(pos == n*2)
        {
            if(is_valid(s)) { ans.push_back(s); cnt++;}
            return;
        }
        for(int i = 0; i <= 1; i++)
        {
            s.push_back(mp[i]);
            dfs(pos + 1,n);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        dfs(0,n);
        return ans;
    }
    int main()
    {

        vector<string>a;
        a = generateParenthesis(8);
        for(int i = 0; i < a.size();i++)
        {
            for(int j = 0; j < a[0].size();j++)
                cout<<a[i][j];
            cout<<endl;
        }
        cout<<cnt<<endl;
        return 0;
    }