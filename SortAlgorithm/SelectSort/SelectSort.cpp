//
// Created by jjh on 2023/12/29.
//

#include <iostream>
#include <vector>
using namespace std;
void SelectInsert(vector<int>&v)
{
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[minj])
                minj = j;
        if (minj != i)
            swap(v[i],v[minj]);
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    SelectInsert(data);
    for(int d : data)cout<<d<<" ";
    return 0;
}