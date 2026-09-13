// searching a element in rotated array
//[3,4,5,7,9]  -> [9,3,4,5,7]  ->[7,9,3,4,5]  ->[5,7,9,3,4] rotated three times
/*search peak element divide the array in two halves if target lies in first half bs there else bs on second half*/
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums,int mid){
    if(nums[0]>nums[mid]){
        return true;
    }else{
        return false;
    }
}

int solve(vector<int> &nums){
    int lo=0,hi=nums.size()-1;
    int ans=hi+1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(nums,mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}

int bs(int lo,int hi,vector<int> &nums,int target){
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target){
            ans=mid;
            return ans;
        }else if(nums[mid]<target){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int pivot=solve(nums);

    if(target>=nums[0] && target<=nums[pivot-1]){
        cout<<bs(0,pivot-1,nums,target);
    }else{
        cout<<bs(pivot,n-1,nums,target);
    }
    return 0;
}
