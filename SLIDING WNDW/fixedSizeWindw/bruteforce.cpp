//finding minimum/max/prime/.... from a fixed size window in O(n*k)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<=n-k;i++){//O(n)   ->O(n*k)
        int mn=INT_MAX;
        for(int j=i;j<i+k;j++){//O(k)
            mn=min(mn,arr[j]);
        }
        cout<<mn<<" ";
    }
    return 0;
}