/*
LC 2302 - Count Subarrays With Score Less Than K
Score of a subarray = (sum of its elements) * (its length).
Return the number of subarrays whose score is strictly less than k.
Example: nums = [2,1,4,3,5], k = 10 -> 6
         [2] [1] [4] [3] [5] [2,1]
            ([2,1] = 3*2 = 6 < 10, [1,4] = 5*2 = 10 not < 10)
            [2 ]1 4 3 5  2*1=2<10   [2] 1
            [2 1] 4 3 5  3*2=6<10  [1] [2,1] 2
            [2 1 4] 3 5 9*3=27>10  no subarray
            2 [1 4] 3 5 5*2=10<10(false) no subarry
            2 1 [4] 3 5 4*1=4<10  [4]   1
            2 1 [4 3] 5 7*2=14>10 no subarray
            2 1 4 [3] 5 3*1=3<10  [3]  1
            2 1 4 [3 5] 8*2=16>10 no subarray
            2 1 4 3 [5] 5*1=5<10 [5] 1
            possible subarrays -> [2],[1],[2,1],[4],[3],[5] (6)
*/
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums,long long k){
    int n=nums.size();
    int tail=0,head=-1;
    long long ans=0;
    long long curr_sum=0;
    long long prdct=1;

    while(tail<n){
        while(head+1<n && (curr_sum+nums[head+1])*(head-tail+2)<k){
            head++;
            curr_sum+=nums[head];
        }ans+=(head-tail+1);
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
    int n;
    long long k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    long long res=solve(nums,k);
    cout<<res;
    return 0;
}
