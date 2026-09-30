#include <bits/stdc++.h>
using namespace std;

vector<int> minElemWndw(vector<int> &arr,int k){
    int n=arr.size();
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]>=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(arr[dq.front()]);
        }
        return ans;

    }
}

void main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> res=minElemWndw(arr,k);
    for(auto it:res){
        cout<<it<<" ";
    }

}