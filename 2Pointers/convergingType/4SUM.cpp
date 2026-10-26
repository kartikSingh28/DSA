/*
4Sum (LC 18)
Return all unique quadruplets with a + b + c + d = target (here target = 0).
Example: [1,0,-1,0,-2,2] -> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            int k=j+1,l=n-1;
            int target=-(nums[i]+nums[j]);
            while(k<l){
                if(nums[k]+nums[l]==target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }else if(nums[k]+nums[l]<target){
                    k++;
                }else{
                    l--;
                }
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
