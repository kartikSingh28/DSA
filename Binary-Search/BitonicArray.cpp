// bitonic array is finding the peak elenment from array like there is a hight till peak then there is drop
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr,int mid){
    if(mid==arr.size()-1){
        return true;
    }
    if(arr[mid]>arr[mid+1]){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    int lo=0,hi=n-1;
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
    return 0;
}