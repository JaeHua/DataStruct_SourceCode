//
// Created by jjh on 2023/12/29.
//

#include <iostream>
#include <vector>
using namespace std;
void shiftDown(vector<int>&v,int low,int high)
{
    int i = low;
    int j = 2*i+1; //左孩子
    int tmp = v[i]; //临时保存根结点
    while(j <= high)
    {
        if(j<high&&v[j]<v[j+1])j++;//j指向最大的孩子结点
        if(tmp<v[j])
        {
            v[i] = v[j];
            i = j;
            j = 2*i+1;//继续向下筛选
        }else break;
    }
    v[i] = tmp;//原根结点放入最终位置
}
void shiftUp(vector<int>&v,int j)
{
    int i = (j - 1)/2;
    while(true)
    {
        if(v[j]>v[i])
            swap(v[i],v[j]);
        if(i == 0)break;
        j = i;
        i = (j - 1)/2;//继续向上调整
    }
}
void HeapSort(vector<int>&v,int n)
{
    for(int i = n/2 - 1;i>=0;i--)//从最后一个分支结点开始
        shiftDown(v,i,n-1);
    for(int i =  n-1;i>0;i--)
    {
        swap(v[0],v[i]);
        shiftDown(v,0,i-1);//对无序区v[0...i-1]继续筛选
    }
}
int main()
{
    vector<int> data = {5,3,4,6,9,8,2,1,0,7};
    HeapSort(data,data.size());
    for(int d : data)cout<<d<<" ";
    return 0;
}