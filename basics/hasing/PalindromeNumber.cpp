/*
LC 9 - Palindrome Number
Return true if the integer reads the same forwards and backwards.
Example: 121 -> true, -121 -> false ("121-"), 10 -> false ("01")
*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int n){
    long long rev=0;
    int x=n;
    while(n>0){
        int d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    if(rev==x){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    bool res=solve(n);
    cout<<res;
    return 0;
}