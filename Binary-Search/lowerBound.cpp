//lower bound(x) -> first element greater then or equal to x
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr,int mid,int x){
    if(arr[mid]>=x){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int lo=0,hi=n-1;
    int ans=hi+1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(arr,mid,x)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}