#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums,int k){
    int n=nums.size();
    vector<int> freq(10110,0);
    int distnct_cnt=0;
    long long curr_sum=0;
    vector<long long> ans;
    for(int i=0;i<n;i++){
        curr_sum+=(long long)nums[i];
        if(freq[nums[i]]==0){
            distnct_cnt++;
        }
        freq[nums[i]]++;
        if(i>=k){
            curr_sum-=(long long)nums[i];
            freq[nums[i-k]]--;
            if(freq[nums[i-k]]==0){
                distnct_cnt--;
            }
        }
        if(i>=k-1){
            if(distnct_cnt==k){
                ans.push_back(curr_sum);
            }
        }
        
    }
    long long MAX=INT_MIN;
    for(int i=0;i<ans.size();i++){
        MAX=max(MAX,ans[i]);
    }
    return MAX;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,k);
    cout<<res<<endl;
    return 0;

}