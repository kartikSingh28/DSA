/*
SHORTEST WINDOW TEMPLATE (minimum window)
Use when the question asks for the SHORTEST subarray / substring that REACHES a goal
(sum >= target, contains all characters of t, ...).

Same head/tail template as the longest window. Only 2 slots change:
                longest window                 shortest window
  eat while     window STAYS valid             window is NOT YET valid
  record        ans = max(...) always          if valid: ans = min(...)
  start ans     0                              INT_MAX (return 0 / "" if it never changed)

For each tail, head grows JUST until the window becomes valid
-> that is the shortest valid window starting at this tail. Then tail moves on.

Example (209): shortest subarray with sum >= 7 in [2,3,1,2,4,3]
  tail 0: [2,3,1,2] sum 8  -> min 4
  tail 1: [3,1,2,4] sum 10 -> min 4
  tail 2: [1,2,4]   sum 7  -> min 3
  tail 3: [2,4,3]   sum 9  -> min 3
  tail 4: [4,3]     sum 7  -> min 2
  tail 5: [3]       sum 3  -> not valid, skip
  answer 2
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums /*, goal */){
    int n=nums.size();
    int tail=0,head=-1;
    int ans=INT_MAX;
    // window state (sum, freq, count ...)

    while(tail<n){
        while(head+1<n && /* window NOT valid yet */ true){
            head++;
            // ADD nums[head] to the window state
        }
        if(/* window valid */ false){
            ans=min(ans,head-tail+1);
        }
        if(tail<=head){
            // REMOVE nums[tail] from the window state
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans==INT_MAX ? 0 : ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    cout<<solve(nums);
    return 0;
}
