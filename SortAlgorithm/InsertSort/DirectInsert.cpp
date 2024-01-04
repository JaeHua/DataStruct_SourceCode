//
// Created by jjh on 2023/1/4.
//

#include <iostream>
#include <vector>
using namespace std;
void DirectInsert(vector<int>&v)
{
    int len = v.size();
    for(int i = 1; i < len; i++)//第一个是不需要比较的，一个元素本身就是作为了有序区
    {
       if(v[i] < v[i-1])
       {
           int tmp = v[i];
           int j = i - 1;
           do {
               v[j+1] = v[j];
               j--;
           }while(j>=0&&v[j]>tmp);
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