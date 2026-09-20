/* Given `weights` and `days`, ship all packages within `days` days.
   Packages must be shipped in the given order, and daily weight <= ship capacity.
   Find the minimum possible ship capacity.
   Example: weights=[1,2,3,4,5,6,7,8,9,10], days=5 -> 15
   Possible split: [1,2,3,4,5], [6,7], [8], [9], [10] */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums,int mid,int days){
    int curr_wt=0;
    int day=0;
    for(int i=0;i<nums.size();i++){
        if(curr_wt+nums[i]<=mid){
            curr_wt+=nums[i];
        }else{
            day++;
            curr_wt=nums[i];
        }
        if(day>days) return false;
    }
    return true;
}

int  main(){
    int n,days;
    cin>>n>>days;
    vector<int> weights(n);
    for(int i=0;i<n;i++)cin>>weights[i];
    int lo=0,hi=0;
    for(int i=0;i<n;i++){
        lo=max(lo,weights[i]);
        hi+=weights[i];
    }

    int ans=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(weights,mid,days)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return 0;
}