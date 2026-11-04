/*
LC 1493 - Longest Subarray of 1's After Deleting One Element
Delete exactly one element. Return the longest subarray of only 1's left.
Example: [0,1,1,1,0,1,1,0,1] -> 5   (delete the 0 at index 4)
[0] 1 1 1 0 1 1 0 1 len =0
[0 1] 1 1 0 1 1 0 1 len =1
[0 1 1] 1 0 1 1 0 1 len =1
[0 1 1 1] 0 1 1 0 1 len = 2
0 [1 1 1] 0 1 1 0 1
0 [1 1 1 0] 1 1 0 1
0 [1 1 1 0 1] 1 0 1
0 [1 1 1 0 1 1] 0 
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n=nums.size();
    int tail=0,head=-1;
    int ans=0;
    int cnt_zero=0;
    while(tail<n){
        while(head+1<n && (cnt_zero!=1 || nums[head+1]==1)){
            head++;
            if(nums[head]==0){
                cnt_zero++;
            }
        }ans=max(ans,(head-tail));
        if(tail<=head){
            if(nums[tail]==0){
                cnt_zero--;
            }tail++;

        }else{
            tail++;
            head=tail-1;
        }

    }
    return ans;
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
