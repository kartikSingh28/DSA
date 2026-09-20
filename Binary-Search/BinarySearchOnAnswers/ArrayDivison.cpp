/*You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &nums,long long mid,int  k){
    long long curr_sum=0;
    int subarray=1;
    for(long long i=0;i<nums.size();i++){
        if(curr_sum+nums[i]<=mid){
            curr_sum+=nums[i];
        }else{
            curr_sum=nums[i];
            subarray++;
        }
        if(subarray>k)return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }
    long long lo=0,hi=0;
    for(long long  i=0;i<n;i++){
        lo=max(lo,nums[i]);
        hi+=nums[i];
    }
    long long ans=hi;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        if(check(nums,mid,k)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}