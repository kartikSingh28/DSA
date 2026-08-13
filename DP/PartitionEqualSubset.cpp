#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

bool rec(int level,int curr_sum,vector<int> &nums,int target){
    if(level==nums.size()){
        if(curr_sum==target){
            return true;
        }else{
            return false;
        }
    }
    if(dp[level][curr_sum]!=-1){
        return dp[level][curr_sum];
    }
    bool take=false;
    bool not_take=rec(level+1,curr_sum,nums,target);
    if(curr_sum+nums[level]<=target){
        take=rec(level+1,curr_sum+nums[level],nums,target);
    }
    return dp[level][curr_sum]=take || not_take;
}

bool partionSet(vector<int> &nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum%2!=0)return false;
    int target=sum/2;
    
    dp.assign(nums.size()+1,vector<int>(target+1,-1));
    return rec(0,0,nums,target);


}

signed main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    partionSet(nums);
}