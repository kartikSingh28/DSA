/*
LC 217 - Contains Duplicate

Given an integer array nums, return true if any value appears at least twice,
and false if every element is distinct.
Constraints: 1 <= n <= 10^5, -10^9 <= nums[i] <= 10^9

Example:
nums = [1,2,3,1]  -> true
nums = [1,2,3,4]  -> false
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums){
    map<int,int> mp;
    for(auto x:nums){
        mp[x]++;
    }
    for(auto &v: mp){
        if(v.second>=2){
            return true;
        }
    }
    return false;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    bool ans=solve(nums);
    cout<<ans<<endl;
    return 0;
}