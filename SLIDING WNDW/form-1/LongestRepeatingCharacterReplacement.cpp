/*
LC 424 - Longest Repeating Character Replacement
Replace at most k characters of s (uppercase letters) so that a substring becomes all the
same letter. Return the length of the longest such substring.
Example: s = "AABABBA", k = 1 -> 4   ("AABA" -> "AAAA")

Idea: it is 1004 where "zeros" = letters that are not the most common one.
      changes = window length - maxFreq <= k. Recompute maxFreq in the eat condition.

Test inputs (s k):
ABAB 2     -> 4
AABABBA 1  -> 4
ABCD 0     -> 1
*/
#include <bits/stdc++.h>
using namespace std;

int Maxfreq(vector<int> &freq){
    int MaxF=0;
    for(int i=0;i<freq.size();i++){
        MaxF=max(MaxF,freq[i]);
    }
    return MaxF;
}
int solve(string &s,int k){
    int n=s.length();
    int tail=0,head=-1;
    int ans=0;
    vector<int> freq(26,0);
    while(tail<n){
        while(head+1<n && ((head-tail+2)-max(Maxfreq(freq),freq[s[head+1]-'A']+1))<=k){
            head++;
            freq[s[head]-'A']++;
        }ans=max(ans,(head-tail+1));
        if(tail<=head){
            freq[s[tail]-'A']--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
    
}

int main(){
    int k;
    string s;
    cin>>s;
    cin>>k;
    int res=solve(s,k);
    cout<<res;
    return 0;
}