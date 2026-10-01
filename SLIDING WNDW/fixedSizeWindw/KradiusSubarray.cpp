/*
LC 2090
For each index i, find the average of elements from
i-k to i+k. If the full range doesn't exist, return -1.

Example:
nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]

For i = 3: [7,4,3,9,1,8,5] -> 37/7 = 5
For i = 4: [4,3,9,1,8,5,2] -> 32/7 = 4
For i = 5: [3,9,1,8,5,2,6] -> 34/7 = 4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,int k){
    int n=nums.size();
    int wndw=2*k+1;
    vector<int> res(n,-1);
    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        if(i>=wndw){
            curr_sum-=nums[i-wndw];
        }
        if(i>=wndw-1){
            int avg=curr_sum/wndw;
            res[i-k]=avg;
        }
    }
    return res;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums,k);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}