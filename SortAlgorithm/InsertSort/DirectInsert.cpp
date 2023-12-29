//
// Created by jjh on 2023/12/29.
//
#include <iostream>
#include <vector>
using namespace std;
void DirectInsert(vector<int>&v)
{
    int n = v.size();
    for(int i = 1; i < n; i++)
    {
        if(v[i] < v[i-1])
        {
            int tmp = v[i];
            int j = i-1;
            do{
                v[j+1] = v[j];
                j--;
            } while (j>=0&&v[j]>tmp);
            v[j+1] = tmp;
        }
    }
}
int main()
{
     vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    DirectInsert(data);
    for(int d : data)cout<<d<<" ";
    return 0;
}