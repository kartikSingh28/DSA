/*
Valid Triangle Number (LC 611)
Count triplets that can form a triangle (sum of any two sides > third).
Example: [2,2,3,4] -> 3
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int count=0;
    for(int i=n-1;i>=2;i--){
        int j=i-1,k=0;
        while(k<j){
            if(nums[j]+nums[k]>nums[i]){
                count+=(j-k);
                j--;
            }else{
                k++;
            }
        }
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int res=solve(nums);
    cout<<res<<endl;
    return 0;
}