/*
LC 1838 - Frequency of the Most Frequent Element
In one operation, pick any index and increase nums[i] by 1. You can do at most k operations.
Return the maximum possible frequency of any element.
Example: nums = [1,2,4], k = 5 -> 3   (1 +3 and 2 +2 -> [4,4,4])
1 2 4
[1] 2 4
[2  2 4
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int k){
    int n=nums.size();
    int head=-1,tail=0;
    long long curr_sum=0;
    int ans=0;
    while(tail<n){
        while(head+1<n && ((long long)((head-tail+2)*nums[head+1])-(curr_sum+nums[head+1]))<=k){
            head++;
            curr_sum+=nums[head];
        }ans=max(ans,head-tail+1);
        if(tail<=head){
            curr_sum-=nums[tail];
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;

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
