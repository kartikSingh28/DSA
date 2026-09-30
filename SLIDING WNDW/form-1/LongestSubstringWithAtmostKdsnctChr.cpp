/*
Given a string s and an integer k. Find the length of the longest substring with at most k distinct characters.

Example:
Input : s = "aababbcaacc", k = 2
Output : 6
*/

#include <bits/stdc++.h>
using namespace std;

int solve(string &s,int k){
    int n=s.size();
    int tail=0,head=-1;
    int ans=0;
    int dsnct=0;
    vector<int> freq(128,0);

    while(tail<n){
        while(head+1<n && (dsnct<k || freq[s[head+1]]>0)){
            head++;
            if(freq[s[head]]==0) dsnct++;
            freq[s[head]]++;
        }
        ans=max(ans,head-tail+1);
        if(tail<=n){
            freq[s[tail]]--;
            if(freq[s[tail]]==0) dsnct--;
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int main(){
    string s;
    int k;
    cin>>s>>k;
    int res=solve(s,k);
    cout<<res<<endl;
    return 0;
}