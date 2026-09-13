// find the minimmum in rotated array
//o(logn)
/*arr=[3,4,5,7,9]  rotated three times
->[9,3,4,5,7]   -> [7,9,3,4,5]   ->  [5,7,9,3,4]
minimum of sorted array=element at index  of first 1 */  
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
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(nums,mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return nums[ans];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve(nums)<<endl;
    return 0;
}
