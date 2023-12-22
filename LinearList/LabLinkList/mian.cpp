//
// Created by 姜杰铧 on 2023/11/1.
//

#include "LabLinkList.cpp"
#include <fstream>
vector<int>ans;
vector<int> solve(int n, int m,LabLinkList list1,LabLinkList list2) {
    vector<int>ans;
    DataNode*p = list1.head->next;
    DataNode*q = list2.head->next,*pre = q;//pre保存q的状态
    if(!p || !q)return {};
    while(p!= nullptr)
    {
        while (q!= nullptr)
        {
            if(p->data[n - 1] == q->data[m - 1])//符合题意
            {
                for(int i = 0; i < list1.head->Col;i++)
                    ans.push_back(p->data[i]);
                for(int j = 0; j < list2.head->Col;j++)
                    ans.push_back(q->data[j]);
            }
            q = q->next;
        }
        q = pre;
        p = p->next;

    }
    return ans;
}
int main(){
    ifstream ifs;
    ifs.open("in.txt");
    int r,c,r1,c1;
    ifs>>r>>c;
    vector<vector<int>>f(r + 1,vector<int>(c + 1));
    for(int i = 0; i < r;i++)
        for (int j = 0; j < c; ++j) {
            ifs>>f[i][j];
        }
    LabLinkList mylist(r,c);
    mylist.CreatListR(f);

    ifs>>r1>>c1;
    vector<vector<int>>f1(r1 + 1,vector<int>(c1 + 1));
    for(int i = 0; i < r1;i++)
        for (int j = 0; j < c1; ++j) {
            ifs>>f1[i][j];
        }
    LabLinkList mylist1(r1,c1);
    mylist1.CreatListR(f1);
//    mylist.disp();
//    mylist1.disp();
    int n,m;
    ifs>>n>>m;
   ans =  solve(n,m,mylist,mylist1);
   int index = 0;
    for(int i = 0; i < ans.size()/(c1 + c);i++)
    {
        for(int j = i*(c1+c); j < i*(c1+c) +c1 + c;j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }

}