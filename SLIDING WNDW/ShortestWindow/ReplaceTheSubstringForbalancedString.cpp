/*
LC 1234 - Replace the Substring for Balanced String
s has only Q, W, E, R and n is a multiple of 4. Balanced = each letter appears n/4 times.
Return the length of the shortest substring you can replace (with anything) to make s balanced.
Example: s = "QQQW" -> 2   (replace "QQ" with "ER")


Test inputs (s):
QWER        -> 0   (already balanced)
QQWE        -> 1
QQQW        -> 2
WQWRQQQW    -> 3
*/
#include <bits/stdc++.h>
using namespace std;

bool ValidOutside(vector<int> &freq,int n){
    for(int i=0;i<freq.size();i++){
        if(freq[i]>n/4){
            return false;
        }
    }
    return true;
}

int solve(string &s){
    int n=s.length();
    int tail=0,head=-1;
    vector<int> freq(128,0);
    for(auto x:s){
        freq[x]++;
    }
    int ans=INT_MAX;

    while(tail<n){
        while(head+1<n && !ValidOutside(freq,n)){
            head++;
            freq[s[head]]--;
        }
        if(ValidOutside(freq,n)){
            ans=min(ans,head-tail+1);
        }
        if(tail<=head){
            freq[s[tail]]++;
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
    cin>>s;
    int res=solve(s);
    cout<<res;
    return 0;
}
