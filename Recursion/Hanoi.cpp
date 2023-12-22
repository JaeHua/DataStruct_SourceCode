//
// Created by 姜杰铧 on 2023/11/8.
//
/*
 * 利用递归巧解汉诺塔问题
 * */
#include<iostream>
using namespace std;
void move(char A,char B)
{
    cout<<A<<"-->"<<B<<endl;
}
void Hanoi(int n,char A,char B,char C)
{
    //从A移到C上
    if(n == 1)
        move(A,C);
    else {
        Hanoi(n - 1, A, C, B);
        move(A,C);
        Hanoi(n-1,B,A,C);
    }
}
int main(){
    int n;
    cin>>n;
    Hanoi(n,'A','B','C');
    return 0;
}