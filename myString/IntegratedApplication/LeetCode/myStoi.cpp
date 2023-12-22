//
// Created by ½ª½Üîü on 2023/10/26.
//
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
        long long ans = 0,tmp = 0;
        int flag = 0,flagg = 0,flaggg = 0,space = 0;
        for(auto ch:s)
        {
            if(ch == ' ')
            {

                if((flag||flagg||flaggg)&&space)break;
                space++;
                continue;
            }
            else if(ch == '+')
            {
                flaggg++;
                if(flaggg<=1&&!flag&&!flagg){   ;continue; }


                break;
            }
            else if( ch == '-')
            {

                if(flagg)
                    break;
                flag++;
                if(flag > 1)
                    break;
                if(!flagg&&flaggg&&flag)break;
            }
            else if(ch>='0'&&ch<='9')
            {



                if(ans>=pow(2,31)){if(flag)return -pow(2,31); ans = pow(2,31) - 1;return ans;}

                ans = 10*ans + ch - '0';
                flagg = 1;
            }
            else
            {

                break;

            }

        }
        if(flag)ans = -ans;
        if(ans < -pow(2,31))ans = -pow(2,31);
        else if(ans>=pow(2,31))ans = pow(2,31) - 1;
        return ans;
    }
    int main()
    {
    string s;
    while(getline(cin,s)) { cout << myAtoi(s)<<endl; }
        return 0;
    }