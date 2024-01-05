//
// Created by jjh on 2024/1/5.
//
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;
int getMid(vector<int>&v,int left,int right)
{
    int pivot = v[left];
    while(left<right)
    {
        while(left<right&&v[right]<=pivot)right--;
        v[left] = v[right];
        while(left<right&&v[left]>=pivot)left++;
        v[right] = v[left];
        v[left] = pivot;
    }
    return left;
}
int quicksort(vector<int>&v,int left,int right,int k)
{
    int mid = -1,len = 0;
    if(left<right)
    {
         mid = getMid(v,left,right);
         len = mid - left + 1;
        if (len < k){
                       mid = quicksort(v, mid + 1, right, k - len);
        }
             else if (len > k){
                       mid = quicksort(v, left, mid - 1, k);
                    }
    }
    return mid;
}

int main()
{
    ifstream ifs;
    ifs.open("in.txt");
    vector<int>v;
    int value = 0;
    while (ifs >> value)
    {
        v.push_back(value);
        if (ifs.get() == '\n')break;
    }
    ifs.close();
    ofstream ofs;
    ofs.open("out.txt");
    int a = quicksort(v,0,v.size()-1,10);
    for (int i = 0 ; i < 9;i++)ofs<<v[i]<<" ";
    ofs<<endl;
    return 0;
}
