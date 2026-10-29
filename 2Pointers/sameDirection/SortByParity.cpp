/*
Sort Array By Parity (LC 905)
Move all even numbers to the front, followed by all odd numbers (any order inside each group).
Example: [3,1,2,4] -> [2,4,3,1]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(nums[i]%2==0){
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
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums);
    for(auto x:res)cout<<x<<" ";
    return 0;

}