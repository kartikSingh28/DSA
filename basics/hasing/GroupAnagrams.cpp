/*
LC 49 - Group Anagrams

Given an array of strings, group the anagrams together (any order).
Anagram = same letters, same counts, different order.
Constraints: 1 <= n <= 10^4, 0 <= word length <= 100, lowercase letters

Example:
strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
*/
// [[ate],[eat],[tin]]  mp{  aet-[ate,eat],aet}

#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> solve(vector<string> &strs){
    unordered_map<string,vector<string>> mp;
    for(auto x:strs){
        string key=x;
        sort(key.begin(),key.end());
        mp[key].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto &x:mp){
        ans.push_back(x.second);
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(auto x:strs){
        cin>>x;
    }
    vector<vector<string>> res=solve(strs);
    for(auto x:res){
        for(auto v:x){
            cout<<v<<" ";
        }
    }
    return 0;
}