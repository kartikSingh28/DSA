#include <bits/stdc++.h>
using namespace std;
int n,k;

bool check(int mid,vector<int> &nums){
 int painters=1;
 int curr=0;
 for(int i=0;i<n;i++){
    if(nums[i]+curr<=mid){
        curr+=nums[i];
    }else{
        painters++;
        curr=nums[i];
    }
    
    if(painters>k) return false;
 }
 return true;
}

int main(){
    cin>>n>>k;
    vector<int> nums(n);

    int lo=0,hi=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        lo=max(lo,nums[i]);
        hi+=nums[i];
    }
    
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,nums)){//NNNNYYYY
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}