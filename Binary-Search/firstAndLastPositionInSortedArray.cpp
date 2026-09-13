/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]*/
#include <bits/stdc++.h>
using namespace std;

bool check1(vector<int> nums,int mid,int target){
    if(nums[mid]>=target)return true;
    else return false;
}

bool check2(vector<int> nums,int mid,int target){
    if(nums[mid]>=target)return true;
    else return false;
}
int lowerBound(vector<int> &nums,int target){
    int lo=0,hi=nums.size()-1;
    int ans=hi+1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check1(nums,mid,target)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> &nums,int target){
    int lo=0,hi=nums.size()-1;
    int ans=hi+1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check2(nums,mid,target)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    int l=lowerBound(nums,target);
    if(nums[l]==target) cout<<"-1"<<" "<<"-1";
    int u=upperBound(nums,target)-1;
    vector<int> ans={l,u};
    return 0;
}