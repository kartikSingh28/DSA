/*
Pythagorean Triplet (GfG)
Return true if there exist a, b, c in the array with a^2 + b^2 = c^2.
Example: [3,2,4,6,5] -> true (3,4,5)
*/
#include <bits/stdc++.h>
using namespace std;//

bool solve(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>=2;i--){
        int j=i-1,k=0;
        while(k<j){
            if((nums[k]*nums[k])+(nums[j]*nums[j])==nums[i]*nums[i]){
                return true;
            }else if((nums[k]*nums[k])+(nums[j]*nums[j])>nums[i]*nums[i]){
                j--;
            }else{
                k++;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    bool res=solve(nums);
    cout<<res;
    return 0;
}