/*
LC 189 - Rotate Array
Rotate the array to the right by k steps, in-place.
Example: nums = [1,2,3,4,5,6,7], k = 3 -> [5,6,7,1,2,3,4]

Idea: k = k % n, then 3 reverses (each one = converging two pointers, swap, i++, j--)
      reverse all          7 6 5 4 3 2 1
      reverse 0..k-1       5 6 7 | 4 3 2 1
      reverse k..n-1       5 6 7 | 1 2 3 4
Time O(n), Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &nums,int i,int j){

}

void solve(vector<int> &nums,int k){

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    solve(nums,k);
    for(int i=0;i<n;i++)cout<<nums[i]<<" ";
    return 0;
}
