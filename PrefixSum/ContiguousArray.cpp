/*
LC 525 - Contiguous Array
Binary array (only 0s and 1s). Return the length of the longest contiguous subarray
(one unbroken block, no skipping) with an EQUAL COUNT of 0s and 1s. Order does not matter.
Example: [1,0,1,1,0] -> 4   ([0,1,1,0], index 1..4: two 0s, two 1s)

Test inputs:
5 / 1 0 1 1 0       -> 4
2 / 0 1             -> 2
3 / 0 1 0           -> 2
4 / 0 0 1 1         -> 4
3 / 1 1 1           -> 0
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int zero_count,one_count;
    int best=0;
    for(int i=0;i<n;i++){
        zero_count=0;
        one_count=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0){
                zero_count++;
            }else if(nums[j]==1){
                one_count++;
            }
            if(zero_count==one_count){
                best=max(best,j-i+1);
            }
        }
    }
    return best;
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
