#include <bits/stdc++.h>
using namespace std;

vector<int> path;
vector<vector<int>> dp;

bool rec(int level,int curr_sum,vector<int> &nums,int k){
    if(level==nums.size()){
        if(curr_sum==k){
            return true;
        }else{
            return false;
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
    return dp[level][curr_sum]=take||not_take;
}

void backTrack(int level,int curr_sum,vector<int> & nums,int k){
    if(level==nums.size()){
        if(curr_sum==k){
            for(auto x:path){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    if(curr_sum+nums[level]<=k && rec(level+1,curr_sum+nums[level],nums,k)){
        path.push_back(nums[level]);
        backTrack(level+1,curr_sum+nums[level],nums,k);
        path.pop_back();
    }
    if(rec(level+1,curr_sum,nums,k)){
        backTrack(level+1,curr_sum,nums,k);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    dp.assign(n+1,vector<int>(k+1,-1));
    backTrack(0,0,nums,k);
    return 0;
}