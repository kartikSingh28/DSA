/*
LC 2401 - Longest Nice Subarray
A subarray is nice if the bitwise AND of every pair of its elements is 0
(no two numbers share a 1-bit). Return the length of the longest nice subarray.
Example: nums = [1,3,8,48,10] -> 3   ([3,8,48])

Test inputs (n / nums):
5 / 1 3 8 48 10    -> 3
5 / 3 1 5 11 13    -> 1
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int used=0;
    int n=nums.size();
    int head=-1,tail=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && (used & nums[head+1])==0){
            head++;
            used |=nums[head];
        }ans=max(ans,head-tail+1);
        if(tail<=head){
            used ^=nums[tail];
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums);
    cout<<res;
    return 0;
}
