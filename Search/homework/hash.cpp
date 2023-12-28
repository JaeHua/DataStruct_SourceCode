//
// Created by jjh on 2023/12/28.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
int ky;
int hashTab[1005];
int a[1005];
void insert(int value)
{
    int d = value % 199;
    while (hashTab[d]!=-1)
        d = (d + 1 )%200;
    hashTab[d] = value;
}
int search(int k,vector<int>&v)
{
    int d = k % 199;
    while (hashTab[d]!=-1&&hashTab[d]!=k)
    {
      v.push_back(hashTab[d]);
      d = (d+1)%200;

    }
    if(hashTab[d]==k)
    {
        v.push_back(hashTab[d]);
        return d;
    }else
        return -1;
}
vector<int>v;
int main(){
    ifstream ifs;
    ifs.open("in.txt");
    ifs>>ky;
    int b,j = 0;
    memset(hashTab,-1, sizeof(hashTab));
    while(ifs>>b)
    {   insert(b);
        if(ifs.get() == '\n')break;

    }
    ifs.close();
    ofstream ofs;
    ofs.open("out.txt");
    if(search(ky,v)!=-1)
    {
        ofs<<"True"<<endl;
        for(auto num : v)
            ofs<<num<<" ";
    }
    else
    {
            ofs<<"False"<<endl;
            for(auto num : v)
                ofs<<num<<" ";
    }
    return 0;
}