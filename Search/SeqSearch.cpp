//
// Created by jjh on 2023/12/21.
//
#include <iostream>
using namespace std;
int n;
int a[105] = {1,2,3,4,5,6,0,-4,9,33};
int SeqSearch()
{
    int i = 0; int r = 10;
    while (i < r && a[i]!=n)
        i++;
    if(i>=r)return -1;
    else return i;
}
int main(){
    cin>>n;
    if(SeqSearch()==-1)printf("%d Not Exists!",n);
    else cout<< n<<" is at "<<SeqSearch()<<endl;
    return 0;
}