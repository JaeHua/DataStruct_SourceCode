//
// Created by jjh on 2024/1/2.
//
#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    cout << s << endl;
    int len = s.length();
    int i = 0;
    int d = 0;
    while (i < len)
    {
        d = 10 * d + (s[i] - '0');
        i++;
    }
    cout << d << endl;
    return 0;
}