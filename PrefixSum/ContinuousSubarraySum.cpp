#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums,int k){
    int n=nums.size();
    int curr_sum=0;
    unordered_map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        int rem=curr_sum%k;
        if(mp.find(rem)!=mp.end()){
            if(i-mp[rem]>=2){
                return true;
            }
        }else{
            mp[rem]=i;
        }
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    bool res=solve(nums,k);
    cout<<res;
    return 0;
}