// determine whether string s is a subsequence of string t or not
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string &s,string &t){
    int i=0,j=0;
    while(i<s.length() && j<t.length()){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    if(i==s.length()){
        return true;
    }else{
        return false;
    }

}

int main(){
    string s,t;
    cin>>s>>t;
    bool res=isSubsequence(s,t);
    if(res)cout<<"yes";
    else cout<<"NO";
    return 0;
}