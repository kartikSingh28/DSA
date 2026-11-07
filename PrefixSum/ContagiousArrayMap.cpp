#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int best=0;
    int curr_sum=0;// treat 0 as -1
    unordered_map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            curr_sum+=1;
        }else{
            curr_sum-=1;
        }
        if(mp.find(curr_sum)!=mp.end()){
            best=max(best,i-mp[curr_sum]);
        }else{
            mp[curr_sum]=i;
        }
    }
    return best;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums);
    cout<<res;
    return 0;
}