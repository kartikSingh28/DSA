//Given an array of Arr of integers and an integer K, Find thenumber of subarry such that no of disticet element in the subarray is smaller than or equal to K
//input
//N=7,K=2;
//arr=[2,3,2,5,5,5,2]
//output=20
#include <bits/stdc++.h>
using namespace std;
//as 10**6 use freq arr
int freq[1000100];
int distinct=0;

void insert(int x){
    if(freq[x]==0)distinct++;
    freq[x]++;
}

void erase(int x){
    freq[x]--;
    if(freq[x]==0)distinct--;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int ans=0;
    int tail=0,head=-1;
    while(tail<n){
        while(head+1<n && freq[arr[head+1]]>0 || distinct<k){
            head++;
            //ds change
            insert(arr[head]);
        }
        //update answer
        //cnt
        ans+=head-tail+1;// if sum of len of all sub array then it would be len*len+1/2
        if(tail<=head){
            erase(arr[tail]);
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}