// finding minimum from a fixed size sliding window in O(nlogk) can be optimised further
#include <bits/stdc++.h>
using namespace std;

vector<int> minUsingMultiSet(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> ans;
    multiset<int> wndw;
    for(int i=0;i<n;i++){
        wndw.insert(arr[i]);//o(logk)

        if(i-k>=0){//expired element
            int expired=arr[i-k];
            wndw.erase(wndw.find(expired));//o(logk)
        }
        if(i>=k-1){
            ans.push_back(*wndw.begin());//O(1)
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> ans=minUsingMultiSet(arr,k);//O(nlogk)
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}