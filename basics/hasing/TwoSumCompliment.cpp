/*
LC 1 - Two Sum

Given an integer array nums and an integer target, return the indices of the
two numbers that add up to target. Exactly one solution exists, and you
can't use the same element twice. Return the indices in any order.
Constraints: 2 <= n <= 10^4, -10^9 <= nums[i], target <= 10^9
Try to do it in less than O(n^2).

Example:
nums = [2,7,11,15], target = 9  0->7  1->2  ..
Output: [0,1]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,int t){
    map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.count(nums[i])){
            return {mp[nums[i]],i};
        }
        int complement=t-nums[i];
        mp[complement]=i;
    }
    return {};


}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums,target);
    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    return 0;
}
