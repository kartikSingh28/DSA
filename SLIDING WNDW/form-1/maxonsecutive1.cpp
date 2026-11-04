/*
Max Consecutive Ones III (LC 1004)              (sliding window, variable size)
Given a binary array nums and an integer k, return the maximum number of
consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input:  nums = [1,1,1,0,0,0,1,1,1,1,0]
, k = 2
[1 1 1 0 0 ]0 1 1 1 1 0    len =5
1 [1 1 0 0] 0 1 1 1 1 0    len =4
1 1 [1 0 0] 0 1 1  1 1 0   len =3
1 1 1 [0 0] 0 0 1 1 1 1  0 len =2
1 1 1 0 [0 ]0 0  1 1 1 1 0 len =1
1 1 1 0 [0 0] 0  1 1 1 1 0 len =2
1 1 1 0 0 [0 ] 0 1 1 1  1 0 len =1
1 1  1 0 0 [0 0] 1 1 1 1 0  len =2
1 1  1 0 0 [0 0 1] 1 1 1 0->  1 1 1 0 0 [0 0 1 1] 1 1 0  len = 3,4
1 1 1 0 0 [0 0 1 1 1 ]1 0  len =5
1 1 1 0 0 [0 0 1 1 1 1] 0   len =6(ans)
1 1 1 0 0 0 0  [1 1 1 1 0] len =4
Output: 6
Explanation: flip the two 0's at index 5 and 10 -> [1,1,1,0,0,1,1,1,1,1,1]
             longest run of 1's is index 5..10 = 6
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int tail=0,head=-1;
    int cnt_zero=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && (cnt_zero<k || nums[head+1])){
            head++;
            if(nums[head]==0){
                cnt_zero++;
            }
        }
        ans=max(ans,(head-tail+1));
        if(tail<=head){
            if(nums[tail]==0){
                cnt_zero--;
            }
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,k);
    cout<<res;
    return 0;
}
