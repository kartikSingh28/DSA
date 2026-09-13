#include <bits/stdc++.h>
using namespace  std;

//we have to find the index of first 1 in the array=[0,0,0,0,1,1,1,1] ans=->4
// tc=O(logn)

int solve(vector<int> &arr){
    int lo=0,hi=arr.size()-1;
    int mid;
    int ans=-1;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(arr[mid]==0){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(solve(arr)!=-1){
        cout<<"element found at index "<<solve(arr)<<endl;
    }else{
        cout<<"there is not 1 in the array";
    }
    return 0;
}