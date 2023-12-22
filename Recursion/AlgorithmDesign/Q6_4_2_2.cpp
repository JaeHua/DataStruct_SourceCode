//
// Created by 姜杰铧 on 2023/11/10.
//
/*递归算法查找String对象中字符c出现的最后位置*/
#include <iostream>
#include <string>
using namespace std;
/*
 * 既然要查找最后出现的位置，那么就逆转过来开始查找，逆转操作用递归实现
 * */
char c = 'd';
/*
 * 思路:如果字符串s为空，返回-1；否则，递归地查找s[1:]中字符c的最后一个位置。如果s[1:]中没有字符c，
 * 则检查s[0]是否为c。如果是，则返回0；否则，返回-1。如果s[1:]中有字符c，则返回该字符在s[1:]中的位置加1
 * */
int find_last(string s, char c) {
    if (s.length() == 0) {
        return -1;
    }
    int index = find_last(s.substr(1), c);
    if (index == -1) {
        if (s[0] == c) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return index + 1;
    }
}
int main(){
    cout<<find_last("abcddefg",c)<<endl;
    return 0;
}