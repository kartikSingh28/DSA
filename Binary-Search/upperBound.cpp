// upperBound(x) element strictly greater than x

/* 
"first occurrence of x" → lowerBound(x)
"last occurrence of x" → upperBound(x) - 1
"how many times does x appear" → upperBound(x) - lowerBound(x)
"smallest element ≥ x" (ceil) → lowerBound(x)
"largest element ≤ x" (floor) → lowerBound(x) - 1
"where would I insert x" → lowerBound(x)
"smallest element > x" → upperBound(x)
*/
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums,int mid,int x){
    if(nums[mid]>x){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    int lo=0,hi=n-1;
    int  ans=hi+1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(nums,mid,x)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return 0;
}