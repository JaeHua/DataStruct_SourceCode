//
// Created by jjh on 2023/12/29.
//

#include <iostream>
#include <vector>
using namespace std;
void BinInsert(vector<int>&v)
{
    int n = v.size();
    for(int i = 1; i < n; i++)
    {
            int tmp = v[i];
           int low = 0,high = i-1;
           while(low<=high)
           {
               int mid = (low + high)/2;
               if(tmp<v[mid])
                   high = mid - 1;
               else
                   low = mid+1;
           }
           for(int j = i - 1; j >= high+1;j--)
               v[j+1] = v[j];
           v[high+1] = tmp;
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    BinInsert(data);
    for(int d : data)cout<<d<<" ";
    return 0;
}