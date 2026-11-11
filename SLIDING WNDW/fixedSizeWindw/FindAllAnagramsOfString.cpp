#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string &s,string &p,int k){
    int n2=s.length();
    int n1=p.length();
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    vector<int> ans;

    for(int i=0;i<n1;i++){
        freq1[p[i]-'a']++;
    }

    for(int i=0;i<n2;i++){
        freq2[s[i]-'a']++;
        if(i>=n1){
            freq2[s[i-n1]-'a']--;
        }
        if(i>=n1-1){
            if(freq1==freq2){
                ans.push_back(i-k+1);
            }
        }
    }
    return ans;

}

int main(){
    string s,p;
    cin>>s;
    cin>>p;
    int k;
    cin>>k;
    
    vector<int> res=solve(s,p,k);
    for(auto x:res)cout<<x<<" ";
    return 0;
}