/*
Remove Duplicates from Sorted Array (LC 26)
Array is sorted. Keep each value once, in-place. Return k = number of unique values;
the first k elements of nums must be the unique values in order.
Example: [0,0,1,1,1,2,2,3,3,4] -> k = 5, nums = [0,1,2,3,4,_,...]
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(j<1 || nums[i]!=nums[j-1]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums);
    cout<<res;
    return 0;
}
