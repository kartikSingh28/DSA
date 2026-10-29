/*
Reverse String (LC 344)
Reverse the string in-place using two pointers.
Example: "hello" -> "olleh"
*/
#include <bits/stdc++.h>
using namespace std;

string solve(string &s){
    int n=s.length();
    for(int i=0,j=n-1;i<j;i++,j--){
        swap(s[i],s[j]);
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    string res=solve(s);
    cout<<res<<endl;
    return 0;
}