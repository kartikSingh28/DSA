/*
LC 53 - Maximum Subarray (Kadane)
Find the contiguous subarray with the largest sum and return that sum.
Example: [-2,1,-3,4,-1,2,1,-5,4] -> 6   ([4,-1,2,1])
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int sum=0;
    int best=nums[0];
    for(int i=0;i<n;i++){
        sum+=nums[i];
        best=max(best,sum);
        if(sum<0){
            sum=0;
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
