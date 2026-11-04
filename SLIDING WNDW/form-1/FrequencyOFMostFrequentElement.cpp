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
