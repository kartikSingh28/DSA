/*
LC 1679 - Max Number of K-Sum Pairs              (two pointers, converging)
In one operation, pick two numbers from the array whose sum is k and remove them.
Return the maximum number of operations you can do.
Example: nums=[1,2,3,4], k=5 -> 2   (1+4, 2+3)
         nums=[3,1,3,4,3], k=6 -> 1 (3+3)

Idea: sort, then Two Sum II. On a match, move BOTH pointers ("remove" = skip past).
My mistake: i <= j paired an element with itself -> must be i < j.
Time O(n log n) (sort), Space O(1). Alt: hashmap O(n).
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n= nums.size();
    int operation=0;
    sort(nums.begin(),nums.end());
    int i=0,j=n-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==k){
            operation++;
            i++;
            j--;
        }else if(sum<k){
            i++;
        }else{
            j--;
        }
    }
    return operation;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums,k);
    cout<<res;
    return 0;
}