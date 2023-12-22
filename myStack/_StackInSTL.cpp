//
// Created by 姜杰铧 on 2023/10/11.
//
//
// Created by 姜杰铧 on 2023/10/11.
//
/**
 * stack<int>st1;   //定义一个整数栈*/
/** stack<int>st2(st1)   由st1栈复制产生st2*/
/** stack<int,vector<int>>//定义stack栈，以vector为底层容器*/
/** stack<int,list<int>>//定义stack栈，以list为底层容器*/

#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack<int>st;
    st.push(1);st.push(2);st.push(3);st.push(4);
    printf("栈顶元素:%d\n",st.top());
    printf("出栈顺序:");
    while(!st.empty())
    {
        printf("%d ",st.top());
        /**并不会返回值*/
        st.pop();
    }
    cout<<"\n";
    return 0;
}