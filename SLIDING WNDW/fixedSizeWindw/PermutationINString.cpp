/*
LC 567 - Permutation in String
Return true if s2 contains a permutation of s1 (same letters, any order, as one substring).
Example: s1 = "ab", s2 = "eidbaooo" -> true   ("ba" is in s2)
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(string &s1,string &s2){
    int n1=s1.length();
    int n2=s2.length();
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);

    for(int i=0;i<n1;i++){
        freq1[s1[i]-'a']++;
    }

    for(int i=0;i<n2;i++){
        freq2[s2[i]-'a']++;
        if(i>=n1){
            freq2[s2[i-n1]-'a']--;
        }
        if(i>=n1-1){
            if(freq1==freq2){
                return true;
            }
        }
        return false;
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    bool res=solve(s1,s2);
    cout<<(res ? "true" : "false");
    return 0;
}
