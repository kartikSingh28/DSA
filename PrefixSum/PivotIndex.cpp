/*
LC 724 - Find Pivot Index
Return the leftmost index where the sum of the elements to its left equals the sum
of the elements to its right (the element itself is not counted). Return -1 if none.
Example: nums = [1,7,3,6,5,6] -> 3   (1+7+3 = 11 = 5+6)

Idea: rightSum = total - leftSum - nums[i]. Time O(n), Space O(1).

Prefix array version (Space O(n)):
    vector<int> prefix(n);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
    for(int i=0;i<n;i++){
        int ls=(i==0) ? 0 : prefix[i-1];
        int rs=prefix[n-1]-prefix[i];
        if(ls==rs) return i;
    }
    return -1;
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int total=0;
    for(int i=0;i<n;i++){
        total+=nums[i];
    }
    int ls=0;
    for(int i=0;i<n;i++){
        int rs=total-ls-nums[i];
        if(ls==rs){
            return i;
        }
        ls+=nums[i];
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int idx=solve(nums);
    cout<<idx;
    return 0;
}
