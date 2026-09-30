/*
Given an array of integers arr and two integers k and threshold,
return the number of sub-arrays of size k whose average is
greater than or equal to threshold.

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4

Output: 3

Explanation:
The sub-arrays [2,5,5], [5,5,5] and [5,5,8]
have averages 4, 5 and 6 respectively.

All other sub-arrays of size 3 have averages less than 4.
 lc 1343*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k,int thrshold){
    int n=nums.size();
    int curr_sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        if(i>=k){
            curr_sum-=nums[i-k];
        }
        if(i>=k-1){
            int avg=curr_sum/k;
            if(avg>=thrshold){
                count++;
            }

        }
    }
    return count;
}

int main(){
    int n,k,thrshold;
    cin>>n>>k>>thrshold;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,k,thrshold);
    cout<<res<<endl;
    return 0;
}