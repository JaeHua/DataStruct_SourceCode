//
// Created by jjh on 2023/12/24.
//
#include <iostream>
#include <vector>
using namespace std;
#define maxn 10005
int n;
int a[maxn];
vector<int>b;
struct tree
{
    int data;
    tree*lchild;
    tree*rchild;
    tree()
    {
        lchild = rchild = nullptr;
    }
    tree(int d){
        data = d;
        lchild = rchild = nullptr;
    }
};
void createTree(tree*&tr,int d)
{
    if(tr == nullptr)
        tr = new tree(d);
    else if(d>tr->data)
        createTree(tr->rchild,d);
    else createTree(tr->lchild,d);
}
void insertTr(tree*&tr)
{
    for(int i = 0; i < n; i++)createTree(tr,a[i]);
}
void inOrder(tree *tr)
{
    if(tr!= nullptr)
    {
        inOrder(tr->lchild);
        b.push_back(tr->data);
        cout<<tr->data<<" ";
        inOrder(tr->rchild);
    }
}
void searchT(tree*tr,int value,int &cnt)
{

    if(tr == nullptr)return ;
    else
    {
        if(value<tr->data)
        {   cnt++;
            searchT(tr->lchild,value,cnt);
        }
        else if(value>tr->data)
        {
            cnt++;
            searchT(tr->rchild,value,cnt);
        }
        else
            return;
    }
}
int main()
{
    cin>>n;
    tree *tr = nullptr;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    insertTr(tr);
    int ans = 0,cnt = 0;
    int dd;
    cin>>dd;
    searchT(tr,dd,cnt);
    cout<<cnt+1<<endl;
    inOrder(tr);
    cout<<endl;

    int left = 0,right = n-1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(b[mid]>dd)
        {
            ans++;
            right = mid - 1;
        }
        else if(b[mid]<dd)
        {
            ans++;
            left = mid + 1;
        }
        else
        {
            ans++;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
10
50 30 80 10 90 95 70 75 60 40
 */