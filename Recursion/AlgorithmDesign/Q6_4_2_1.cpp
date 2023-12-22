//
// Created by 姜杰铧 on 2023/11/10.
//
/*用递归逆置string 对象*/
#include <iostream>
#include <string>
using namespace std;
string ans;
string reverse(string s)
{
    if(s.size() == 0)
        return "";
    else
     return   reverse(s.substr(1)) + s[0];

}
int main(){
    cin>>ans;
    ans = reverse(ans);
    cout<<ans<<endl;
    return 0;
}