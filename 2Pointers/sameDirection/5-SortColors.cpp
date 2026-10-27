/*
Sort Colors (LC 75)  -- Dutch National Flag
Array has only 0, 1, 2. Sort it in-place in one pass, without using sort().
Example: [2,0,2,1,1,0] -> [0,0,1,1,2,2]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            swap(nums[j],nums[i]);
            j++;
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            swap(nums[j],nums[i]);
            j++;
        }
    }
    return nums;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> res=solve(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }
    return 0;
}