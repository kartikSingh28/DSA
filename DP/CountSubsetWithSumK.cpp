#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int rec(int level,int curr_sum,vector<int> &nums,int k){
    if(level==nums.size()){
        if(curr_sum==k){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[level][curr_sum]!=-1){
        return dp[level][curr_sum];
    }
    int take=0;
    int not_take=rec(level+1,curr_sum,nums,k);
    if(curr_sum+nums[level]<=k){
        take=rec(level+1,curr_sum+nums[level],nums,k);
    }
    return dp[level][curr_sum]=take+not_take;
    
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    dp.assign(n+1,vector<int>(k+1,-1));
    return rec(0,0,arr,k);

    return 0;
}