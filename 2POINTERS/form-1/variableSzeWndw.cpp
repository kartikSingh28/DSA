// how many k zero u can convert in a subarray to give the maximum no of 1
#include <bits/stdc++.h>
using namespace std;

void main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    //pointer
    int tail=0,head=-1;//WHY?;
    //ds
    int cnt0=0;
    int ans=0;
    while(tail<n){//
        //eat till u can
        while(head+1<n && ((cnt0<k) || nums[head+1]==1)){//if we can eat it  nums[head+1]==0 &&cnt0<k   || nums[head+1]==1 &&cnt0<=k
            head++;
            //ds change
            if(nums[head]==0)cnt0++;//O(N)head is not reseting i.ie on eveyr tail moves thats y O(N)
            ans=max(ans,head-tail+1);
        }
        //update answer
        cout<<ans<<" ";
        //tail++
        if(tail<=head){
            if(nums[tail]==0)cnt0--;
            tail++;
        }else{
            tail++;
            head=tail-1;//?WHY  head-tail+1=0 -> head=tail-1,tail staritng from 0
        }
    }
}