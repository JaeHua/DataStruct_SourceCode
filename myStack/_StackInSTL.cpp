//
// Created by ������ on 2023/10/11.
//
//
// Created by ������ on 2023/10/11.
//
/**
 * stack<int>st1;   //����һ������ջ*/
/** stack<int>st2(st1)   ��st1ջ���Ʋ���st2*/
/** stack<int,vector<int>>//����stackջ����vectorΪ�ײ�����*/
/** stack<int,list<int>>//����stackջ����listΪ�ײ�����*/

#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack<int>st;
    st.push(1);st.push(2);st.push(3);st.push(4);
    printf("ջ��Ԫ��:%d\n",st.top());
    printf("��ջ˳��:");
    while(!st.empty())
    {
        printf("%d ",st.top());
        /**�����᷵��ֵ*/
        st.pop();
    }
    cout<<"\n";
    return 0;
}