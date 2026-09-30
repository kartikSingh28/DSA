// find avg in every k size window k
#include <bits/stdc++.h>
using namespace std;

double solve(vector<int> &nums,int k){
    int n=nums.size();
    vector<double> avgs;
    double curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=(double)nums[i];
        if(i>=k){
            curr_sum-=(double)nums[i-k];
        }
        if(i>=k-1){
            double avg=curr_sum/k;
            avgs.push_back(avg);

        }
    }
    double ans=avgs[0];
    for(int i=0;i<i-k+1;i++){
        ans=max(ans,avgs[i]);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    double ans=solve(arr,k);
    return 0;
}