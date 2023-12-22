//
// Created by 姜杰铧 on 2023/10/19.
//

/**
 * 利用队列完成杨辉三角的打印
 * */
#include <iostream>
#include <queue>
using namespace std;
void printTriangle(int n)
{
    queue<int>q;
    q.push(1);
    cout<<1<<endl;//输出第一个一
    for(int i = 0; i < n; i++)
    {
        queue<int>tmp;   //临时队列，用于存储上一行的相邻两个数的和
        tmp.push(1);//加入第一行的1

        for(int j = 0; j <i;j++)
        {
            int x = q.front();
            q.pop();
            int y = q.front();
            tmp.push(x + y);
        }
        tmp.push(1);//加入最后一个1
        while(!q.empty())
            q.pop();
        q = tmp;    //队列间是可以赋值的

        while(!tmp.empty())
        {
            cout<<tmp.front()<<" ";
            tmp.pop();
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Enter a number n of the triangle :"<<endl;
    int n;
    cin>>n;
    printTriangle(n);
    return 0;
}