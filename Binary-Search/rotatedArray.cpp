// find how many times a array is rotated
// [1,3,5,7,9]   ->   [9,1,3,5,7]    ->    [7,9,1,3,5]   -> [5,7,9,1,3]
// final rotated array [5,7,9,1,3]

#include <bits/stdc++.h>
using namespace  std;

bool check(vector<int> &arr,int mid){
    if(arr[mid]<arr[0]){
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
    cout<<ans%n<<endl;
    return 0;
}