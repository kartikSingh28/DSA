/*
LC 7 - Reverse Integer
Reverse the digits of a 32-bit signed integer. If the result goes outside the
int range [-2^31, 2^31 - 1], return 0.
Example: 123 -> 321, -123 -> -321, 120 -> 21, 1534236469 -> 0 (overflow)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    long long rev=0;
    while(n!=0){
        int d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    if(rev>INT_MAX || rev<INT_MIN){
        return 0;
    }
    return rev;
}

int main(){
    int n;
    cin>>n;
    int res=solve(n);
    cout<<res;
    return 0;
}
