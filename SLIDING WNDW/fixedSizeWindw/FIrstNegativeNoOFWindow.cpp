/*
GFG - First Negative Integer in Every Window of Size K
For every window of size k, print the first negative number in it (0 if there is none).
Example: arr = [-8,2,3,-6,10], k = 2 -> -8 0 -6 -6
[-8 2] 3 -6 10
-8 [2 3] -6 10
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,int k){
    int n=nums.size();
    //for finding the first negative we take a queue
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            q.push(i);
        }
        if(i>=k){
            if(!q.empty() && q.front()==i-k)q.pop();
        }if(i>=k-1){
            if(q.empty())ans.push_back(0);
            else ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> res=solve(arr,k);
    for(auto x:res)cout<<x<<" ";
    return 0;
}
