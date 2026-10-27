/*
Remove Duplicates from Sorted Array II (LC 80)
Array is sorted. Keep each value at most TWICE, in-place. Return k.
Example: [1,1,1,2,2,3] -> k = 5, nums = [1,1,2,2,3,_]
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(j<2 || nums[i]!=nums[j-2]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums);
    for(int i=0;i<res;i++)cout<<nums[i]<<" ";
    return 0;
}