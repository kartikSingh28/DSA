/*
3Sum (LC 15)
Return all unique triplets [a, b, c] with a + b + c = 0.
Example: [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1])continue;

        int j=i+1,k=n-1;
        int target=-nums[i];
        while(j<k){
            if(nums[j]+nums[k]==target){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
            }else if(nums[j]+nums[k]<target){
                j++;
            }else{
                k--;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<vector<int>> res=solve(nums);
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}