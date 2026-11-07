//cses
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &nums,long long x){
    int n=nums.size();
    map<long long,int> mp;
    mp[0]=1;
    long long curr_sum=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        long long target=curr_sum-x;
        if(mp.find(target)!=mp.end()){
            ans+=mp[target];
        }mp[curr_sum]++;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,x;
    cin>>n>>x;
    vector<long long> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    long long res=solve(nums,x);
    cout<<res;
}