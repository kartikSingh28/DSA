/*
LC 13 - Roman to Integer
Convert a Roman numeral to an integer.
I=1 V=5 X=10 L=50 C=100 D=500 M=1000
A smaller symbol before a bigger one is subtracted: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900
Example: "MCMXCIV" -> 1994   (M=1000, CM=900, XC=90, IV=4)

Test inputs:
III     -> 3
LVIII   -> 58      (L=50, V=5, III=3)
IV      -> 4
IX      -> 9
MCMXCIV -> 1994
MMMCMXCIX -> 3999  (largest valid)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string &s){
    int n=s.length();
    unordered_map<char,int> mp;
    mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    int res=0;
    for(int i=0;i<n;i++){
        if(i+1<n && mp[s[i]]<mp[s[i+1]]){
            res-=mp[s[i]];
        }else{
            res+=mp[s[i]];
        }
    }
    return res;

}

int main(){
    string s;
    cin>>s;
    int res=solve(s);
    cout<<res;
    return 0;
}
