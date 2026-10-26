/*
3Sum Closest (LC 16)
Return the sum of 3 numbers that is closest to target.
Example: [-1,2,1,-4], target 1 -> 2
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int target){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int closest=nums[0]+nums[1]+nums[2];
    for(int i=0;i<n-2;i++){
        int j=i+1,k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(abs(sum-target)<abs(closest-target)){
                closest=sum;
            }if(sum==target){
                return target;
            }else if(sum>target){
                k--;
            }else{
                j++;
            }
        }
    }
    return closest;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,target);
    cout<<res;
    return 0;
}