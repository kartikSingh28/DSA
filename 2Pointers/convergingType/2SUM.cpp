/*
Two Sum (LC 1)
Return indices of the two numbers that add up to target (exactly one answer).
Example: [2,7,11,15], target 9 -> [0,1]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,int target){
    int n=nums.size();
    vector<pair<int,int>> arr(n);   
    for(int i=0;i<n;i++){
        arr[i]={nums[i],i};
    }
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j){
        if(arr[i].first+arr[j].first==target){
            return {arr[i].second,arr[j].second};
        }else if(arr[i].first+arr[j].first<target){
            i++;
        }else{
            j--;
        }
    }
    return {};
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums,target);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}
