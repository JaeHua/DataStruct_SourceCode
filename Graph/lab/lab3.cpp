#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
string aa[maxn];
string bb[maxn];
string c ;
struct nodee
{
    int id;
    int cnt;
}ans[maxn];
void msort(int q,int left, int right) {
    if (left == right) { return; }
    int mid = (left + right) / 2;
    int i = left; int j = mid + 1, k = left;
    msort(q,left, mid);
    msort(q,mid+1, right);
    while(i <= mid && j <= right) {
        if (aa[q][i] <= aa[q][j]) {
            c[k] = aa[q][i]; k++; i++;
        }
        else {
            c[k] = aa[q][j]; k++;j++;
            ans[q].cnt += mid - i + 1;

        }
    }
    while (i <= mid) {
        c[k] = aa[q][i]; k++; i++;
    }
    while (j <= right) {
        c[k] = aa[q][j]; k++; j++;
    }
    for (int i = left; i <= right; i++) {
        aa[q][i] = c[i];
    }

}
bool comp(nodee a,nodee b)
{
    return a.cnt<b.cnt;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m;i++)
    {
        cin>>aa[i];
        bb[i] = aa[i];
        msort(i,0, 9);
        ans[i].id=i;
    }
    sort(ans,ans+m,comp);
    for(int i = 0; i < m;i++)
        cout<<bb[ans[i].id]<<endl;

    return 0;
}
/*
10 5
AACATGAAGG
TTGTGGCCAA
CCCGGGGGGA
ATCGATGCAA
GATCAGATTT
 */