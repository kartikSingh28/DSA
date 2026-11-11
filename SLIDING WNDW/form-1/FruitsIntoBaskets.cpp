#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int k=2;
    vector<int> freq(100110,0);
    int distinct_cnt=0;
    int ans=0;

    int head=-1,tail=0;
    while(tail<n){
        while(head+1<n &&(distinct_cnt<k || freq[nums[head+1]]!=0)){
            head++;
            if(freq[nums[head]]==0){
                distinct_cnt++;
            }
            freq[nums[head]]++;
        }ans=max(ans,(head-tail+1));
        if(tail<=head){
            freq[nums[tail]]--;
            if(freq[nums[tail]]==0){
                distinct_cnt--;
            }
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> fruits(n);
    for(int i=0;i<n;i++)cin>>fruits[i];
    int res=solve(fruits);
    cout<<res;
    return 0;
}