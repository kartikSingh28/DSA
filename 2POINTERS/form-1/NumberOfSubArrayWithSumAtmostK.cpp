/*Problem: Count Subarrays With Sum ≤ K

Given an array of N non-negative integers, count the number of contiguous subarrays whose sum is less than or equal to K.

Input

First line: T — number of test cases.
For each test case:
First line: N K
Second line: N integers A[i]

Input:
3
5 3
5 1 2 3 3
6 3
2 1 5 0 2 1
4 5
7 6 1 2

Output:
5
6
5*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int tail=0,head=-1;
    int sum=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && sum+nums[head+1]<=k){
            head++;
            sum+=nums[head];
        }
        ans+=(head-tail+1);
        if(tail<=head){
            sum-=nums[tail];
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        cout<<solve(nums,k);
    }
    
    return 0;
}