/*
LR Sum Query (AlgoZenith)

Given N integers and Q queries (L, R), 1-based.
For each query print (A[L] + A[L+1] + ... + A[R]) % (1e9+7).
Constraints: 1 <= N, Q <= 10^6, -10^9 <= A[i] <= 10^9, 1 <= L <= R <= N

Example:
3 3
1 2 3
1 1
1 3
2 3
Output:
1
6
5
*/
#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    vector<long long> prefix(n,0);
    for(int i=0;i<n;i++)cin>>nums[i];
    prefix[0]=nums[0];
    for(int i=1;i<n;i++){
        prefix[i]=(prefix[i-1]+nums[i])%MOD;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        long long ans;
        if(l==0) ans=prefix[r]%MOD;
        else ans=(prefix[r]-prefix[l-1])%MOD;
        ans=(ans+MOD)%MOD;
        cout<<ans<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
