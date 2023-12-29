//
// Created by jjh on 2023/12/29.
//
//
// Created by jjh on 2023/12/29.
//
#include <iostream>
#include <vector>
using namespace std;
void ShellInsert(vector<int>&v)
{
    int n = v.size();
    int d = n / 2;
    while(d>0)
    {
        for(int i = d; i  < n; i++)
        {
            if(v[i]<v[i-d])
            {
                int tmp = v[i];
                int j = i - d;
                do{
                    v[j+d] = v[j];
                    j = j-d;
                }while(j>=0&&v[j]>tmp);
                v[j+d] = tmp;
            }
        }
        d = d / 2;
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    ShellInsert(data);
    for(int d : data)cout<<d<<" ";
    return 0;
}