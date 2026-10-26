/*
Boats to Save People (LC 881)
Each boat carries at most 2 people with total weight <= limit.
Return the minimum number of boats.
Example: [3,2,2,1], limit 3 -> 3
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int limit){
    int n=nums.size();
    int i=0,j=n-1;
    int boats=0;
    sort(nums.begin(),nums.end());
    while(i<=j){
        int curr_wt=nums[i]+nums[j];
        if(curr_wt<=limit){
            boats++;
            i++;
            j--;
        }else{
            boats++;
            j--;
        }
    }
    return boats;
}

int main(){
    int n,limit;
    cin>>n>>limit;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,limit);
    return 0;
}