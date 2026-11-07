/*
LC 560 - Subarray Sum Equals K
Count the subarrays whose sum is exactly k (numbers can be negative).
Example: nums = [1,2,3], k = 3 -> 2   ([1,2] and [3])

Idea: running sum went from (sum - k) at an earlier point to sum now -> exactly k added in between.
      map: running sum -> how many times it was reached. mp[0] = 1 (before the array).
      each index: count += mp[sum - k]  (look up), then mp[sum]++  (store MY sum, not the target).

Test inputs (n k / nums):
3 3 / 1 2 3               -> 2
3 2 / 1 1 1               -> 2
8 7 / 3 4 7 2 -3 1 4 2    -> 4
4 1 / 1 -1 1 1            -> 5
3 0 / 0 0 0               -> 6
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int count=0;
    int curr_sum=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        int target=curr_sum-k;
        if(mp.find(target)!=mp.end()){
            count+=mp[target];
        }
        mp[curr_sum]++;
    }
    return count;
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