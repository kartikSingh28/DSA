#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums,long long mid,long long t){
    long long curr_prdct=0;
    for(int i=0;i<nums.size();i++){
        curr_prdct+=mid/nums[i];
        if(curr_prdct>=t)return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    long long t;
    cin>>n>>t;
    vector<int> time(n);
    for(int i=0;i<n;i++)cin>>time[i];

    long long lo=1,hi=0;
    for(long long i=0;i<n;i++){
        hi=max(hi,(long long)time[i]);
    }
    hi*=t;
    long long ans=hi;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        if(check(time,mid,t)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}