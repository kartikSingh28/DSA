// we have to find the number of subarrays whose product is exactly less than k
/*eg Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
   int n=nums.size();
   int tail=0,head=-1;
   int product=1;
   int ans=0;
   while(tail<n){
    while(head+1<n && product*nums[head+1]<k){
        head++;
        product*=nums[head];
    }
    ans+=(head-tail+1);
    if(tail<=head){
        product/=nums[tail];
        tail++;
    }else{
        tail++;
        head=tail-1;
    }
  }
  return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    cout<<solve(nums,k)<<endl;
}