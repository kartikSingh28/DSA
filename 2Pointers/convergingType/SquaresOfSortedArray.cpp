/*
Squares of a Sorted Array (LC 977)
nums is sorted (can have negatives). Return the squares of every number, also sorted.
Example: [-4,-1,0,3,10] -> [0,1,9,16,100]

My trace:
i=0,j=4
[-4,-1,0,3,10] i=0,j=3
[9,-1,0,16,100]i=0,j=2
[0,-1,9,16,100]i=0,j=1
[0,1,9,16,100] brute force O(nlogn)--->O(n)

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int n=nums.size();
    int i=0,j=n-1,k=n-1;
    vector<int> res(n);
    while(i<=j){
        int left=nums[i]*nums[i];
        int right=nums[j]*nums[j];
        if(left<right){
            res[k]=right;
            j--;
        }else{
            res[k]=left;
            i++;
        }
        k--;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> res=solve(nums);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}