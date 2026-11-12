/*
LC 76 - Minimum Window Substring
Return the shortest substring of s that contains every character of t
(including duplicates). Return "" if there is none.
Example: s = "ADOBECODEBANC", t = "ABC" -> "BANC"

Test inputs (s t):
ADOBECODEBANC ABC   -> BANC
a a                 -> a
a aa                -> ""   (t needs two a's)
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &freq1,vector<int> &freq2){
    for(int i=0;i<freq2.size();i++){
        if(freq2[i]<freq1[i]){
            return false;
        }
    }
    return true;
}

string solve(string &s,string &t){
    int n1=s.length();
    int n2=t.length();
    vector<int> freq1(128,0);// for t
    vector<int> freq2(128,0);// for s

    for(auto x:t){
        freq1[x]++;
    }
    int ans=INT_MAX;
    int start=0;
    int tail=0,head=-1;

    while(tail<n1){
        while(head+1<n1 && !isValid(freq1,freq2)){
            head++;
            freq2[s[head]]++;
        }
        if(isValid(freq1,freq2)){
            if(head-tail+1<ans){
                ans=head-tail+1;
                start=tail;
            }
        }
        if(tail<=head){
            freq2[s[tail]]--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    if(ans==INT_MAX){
        return "";
    }else{
        return s.substr(start,ans);
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    string res=solve(s,t);
    cout<<res;
    return 0;
}
