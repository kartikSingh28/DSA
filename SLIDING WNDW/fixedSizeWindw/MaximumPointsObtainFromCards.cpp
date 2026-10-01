/*
LC 1423
Take exactly k cards from either end.
Return the maximum possible score.

Example:
cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
if taken from last  1 2 3 4 
if  all taken from  left 4 5 6 1
2 first 1 end   3 4 5 6 
1 first 2 end 2 3 4 5 

arrangin  [1 2 3 4 ] 5 6 1 windwsz=n-k
           1 [2 3 4 5] 6 1
           1 2 [3 4 5 6] 1
           1 2 3 [4 5 6 1]

*/ 
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int totalScore=0;
    for(int i=0;i<n;i++){
        totalScore+=nums[i];
    }
    int wndw=n-k;
    int curr_sum=0;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        if(i>=wndw){
            curr_sum-=nums[i-wndw];
        }
        if(i>=wndw-1){
            mn=min(mn,curr_sum);
        }

    }
    return totalScore-mn;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,k);
    return 0;
}