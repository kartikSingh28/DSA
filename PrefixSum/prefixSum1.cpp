/*
Prefix Sum - basic template

prefix[i] = sum of the first i elements (prefix[0] = 0, size n+1)
sum(l..r) = prefix[r+1] - prefix[l]      (0-indexed l, r)

Complexity:
Build  : O(n) time, O(n) extra space
Query  : O(1) time each
Total  : O(n + q)   vs  O(n * q) by looping each query

Input:
n
n numbers
q
q lines of: l r

Example:
6
2 4 1 3 5 2
3
1 4
0 3
3 3
Output:
13
10
3
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<long long> prefix(n+1,0);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;//O(1)
    }//O(n+q) for q queries
    return 0;
}
