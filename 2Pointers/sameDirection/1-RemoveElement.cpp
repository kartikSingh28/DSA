/*
Remove Element (LC 27)
Remove all occurrences of val in-place. Return k = count of elements left;
the first k elements of nums must be the kept ones (order doesn't matter).
Example: [3,2,2,3], val 3 -> k = 2, nums = [2,2,_,_]
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,val;
    cin>>n>>val;
    vector<int> nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];
    int slow=0;
    for(int fast=0;fast<n;fast++){
        if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow++;
        }
    }
    cout<<slow<<endl;
    return 0;
}