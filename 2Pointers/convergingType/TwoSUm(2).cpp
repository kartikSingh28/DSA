/*
Two Sum II - Input Array Is Sorted (LC 167)
Array is sorted. Return 1-indexed positions of the two numbers that add up to target.
Example: [2,7,11,15], target 9 -> [1,2]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,int target){
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
        if(nums[i]+nums[j]==target){
            return {i+1,j+1};
        }else if(nums[i]+nums[j]<target){
            i++;
        }else{
            j--;
        }
    }
    return {};
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums,target);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}
