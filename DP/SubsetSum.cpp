//problem is same as sum wth sum K instead w have to return true or false if there exits a subset with its sum equals to the given sum or not444

/**Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30. */
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
    int take=0;
    int not_take=rec(level+1,curr_sum,nums,target);
    if(curr_sum+nums[level]<=target){
        take=rec(level+1,curr_sum+nums[level],nums,target);
    }
    return dp[level][curr_sum]=take || not_take;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    dp.assign(n+1,vector<int>(target+1,-1));
    return rec(0,0,nums,target);

}