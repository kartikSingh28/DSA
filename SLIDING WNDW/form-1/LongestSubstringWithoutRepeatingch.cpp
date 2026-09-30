// longest substring without repeating characters]
/*
 abcabcbb   3
 [a]bcabcbb     [ab]cabcbb   [abc]abcbb  -> a[bca]bcbb
   ab[cab]cbb   abc[abc]bb  abcabcb[b]
   only eat till freq[s[i]-'a]==1  freq[s[i]-'a]++ head++
   ans=0,ans=max(ans,head-tail+1);
   shrink window freq[s[i]-'a']>1 tail++ freq[s[i]-'a']--

   //edge case 0 size windw
   tail++;head=tail-1
*/

#include <bits/stdc++.h>
using namespace std;

int solve(string &s,int k){
    int n=s.size();
    int ans=0;
    vector<int> freq(128,0);
    int tail=0,head=-1;
    while(tail<n){
        while(head+1<n && freq[s[head+1]]==0){
            head++;
            if(freq[s[head]]==0){
                freq[s[head]]++;
            }
        }
        ans=max(ans,head-tail+1);
        if(tail<=head){
            freq[s[tail]]--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    int res=solve(s,k);
    return 0;
}