/*
Move Zeroes (LC 283)
Move all 0s to the end in-place, keeping the order of non-zero elements.
Example: [0,1,0,3,12] -> [1,3,12,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
    }
    for(int i=j;i<n;i++){
        nums[i]='0';
    }
    return nums;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}
