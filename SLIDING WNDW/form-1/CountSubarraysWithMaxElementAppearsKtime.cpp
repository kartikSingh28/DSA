/*
LC 2962 - Count Subarrays Where Max Element Appears at Least K Times
Return the number of subarrays where the maximum element of the whole array
appears at least k times.
Example: nums = [1,3,2,3,3], k = 2 -> 6
         [1,3,2,3] [1,3,2,3,3] [3,2,3] [3,2,3,3] [2,3,3] [3,3] atmost<=3
         [1] 3 2 3 3   9 subarrays for atmost
         [1 3] 2 3 3
         [1 3 2] 3 3 
         [1 3 2 3] 3
         1 [3 2 3] 3 
        1 3 [2 3] 3
        1 3 [2 3 3]
        1 3 2[ 3 3]
        1 3 2 3 [3]
*/
#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums,int MaX,int k){
    int n=nums.size();
    int tail=0,head=-1;
    int count_max=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && (count_max<k || nums[head+1]!=MaX)){
            head++;
            if(nums[head]==MaX){
                count_max++;
            }
        }ans+=(head-tail+1);
        if(tail<=head){
            if(nums[tail]==MaX){
                count_max--;
            }tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int MaX=INT_MIN;
    for(int i=0;i<n;i++){
        MaX=max(MaX,nums[i]);
    }
    long long total=(long long)n*(n+1)/2;
    return total-atMost(nums,MaX,k-1);

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