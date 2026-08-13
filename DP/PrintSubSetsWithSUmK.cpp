#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
//backtracking O(2**n*n)


void print(int level,int curr_sum,vector<int> &nums,int k){
    if(level==nums.size()){
        if(curr_sum==k){
            for(int x:subset){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return ;
    }
    subset.push_back(nums[level]);
    print(level+1,curr_sum+nums[level],nums,k);
    subset.pop_back();

    print(level+1,curr_sum,nums,k);

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    print(0,0,nums,k);
    return 0;

}