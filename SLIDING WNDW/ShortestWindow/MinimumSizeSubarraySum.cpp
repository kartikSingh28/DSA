/*
LC 209 - Minimum Size Subarray Sum
All numbers are positive. Return the length of the SHORTEST subarray whose sum is >= target.
Return 0 if there is none.
Example: target = 7, nums = [2,3,1,2,4,3] -> 2   ([4,3])

Test inputs (n target / nums):
6 7 / 2 3 1 2 4 3        -> 2
3 4 / 1 4 4              -> 1
8 11 / 1 1 1 1 1 1 1 1   -> 0   (total is only 8)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int target){
    int n=nums.size();
    int tail=0,head=-1;
    int curr_sum=0;
    int ans=INT_MAX;

    while(tail<n){
        while(head+1<n && (curr_sum<target)){
            head++;
            curr_sum+=nums[head];
        }
        if(curr_sum>=target){
            ans=min(ans,head-tail+1);
        }
        if(tail<=head){
            curr_sum-=nums[tail];
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    if(ans==INT_MAX){
        return 0;
    }else{
        return ans;
    }

}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,target);
    cout<<res;
    return 0;
}
