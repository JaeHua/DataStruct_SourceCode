//
// Created by ½ª½Üîü on 2023/10/25.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> nums(5);
int shortestSubarray(vector<int>& nums, int k) {
//    int n = nums.size();
//    vector<int>q(n*2);
//    int head = 1,tail  = 0;
//    int ans = INT_MAX;
//    for(int i = 0; i < n;i++)
//    {
//        int tmp = q[tail] + nums[i];
//        tail++;
//        q[tail] = tmp;
//        if(q[tail]>=k)
//        {
//            ans = min(ans,tail - head + 1);
//            // memset(q,0,sizeof(q));
//            fill(q.begin(),q.end(),0);
//            //i¼ÇµÃ»ØËİ
//
//            head++;
//            i = head - 1;
//            tail = head - 1;
//            i--;
//
//        }
//
//    }
//    return ans == INT_MAX ? -1:ans;
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int res = n + 1;

    for(int right = 0; right < n; right++) {
        sum += nums[right];
        while(sum >= k) {
            res = min(res, right - left + 1);
            sum -= nums[left++];
        }
    }

    return res == n + 1 ? -1 : res;
}
int main(){
    nums[0] = 84;
    nums[1] = -37;
    nums[2] = 32;
    nums[3] = 40;
    nums[4] = 95;
    int ans = shortestSubarray(nums,150);
    cout<<ans<<endl;
    return 0;
}