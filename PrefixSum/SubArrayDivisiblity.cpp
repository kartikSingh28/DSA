/*
CSES 1662 - Subarray Divisibility
Given n numbers, count the subarrays whose sum is divisible by n.
Input: first line n, second line the n numbers (the divisor is n itself, no separate k).
Example: n = 5, [3,1,2,7,4] -> 1   ([1,2,7] = 10)

Idea: same as LC 974. Same remainder (sum % n) at two positions -> the block between is divisible.
      map: remainder -> how many times seen, mp[0] = 1. Fix negative remainders with + n.
      long long: running sum up to 2*10^14, answer up to ~2*10^10.
*/
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &nums,long long k){
    int n=nums.size();
    long long curr_sum=0;
    long long count=0;
    map<long long,long long> mp;
    mp[0]=1;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        long long rem=curr_sum%k;
        if(rem<0){
            rem+=k;
        }
        if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
        }
        mp[rem]++;
    }
    return count;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    long long res=solve(nums,n);
    cout<<res;
}
