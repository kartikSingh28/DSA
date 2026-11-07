/*
LC 204 - Count Primes
Return how many prime numbers are strictly less than n.
Example: n = 10 -> 4   (2, 3, 5, 7)

Test inputs:
10 -> 4
0  -> 0
1  -> 0
2  -> 0     (2 itself is not counted: strictly less than n)
3  -> 1
100 -> 25
5000000 -> 348513   (needs the sieve, a check-every-number loop is too slow)

Brute force (my first try, fixed): count factors from j=1 to i, prime if exactly 2.
O(n^2) -> Time Limit Exceeded for big n.
    for(int i=1;i<n;i++){
        int fact_count=0;
        for(int j=1;j<=i;j++){          // start at 1, not 2
            if(i%j==0) fact_count++;
        }
        if(fact_count==2) count++;
    }

Sieve of Eratosthenes: assume all prime, cross out multiples of each prime.
Outer loop only up to sqrt(n), inner starts at i*i. Time O(n log log n).
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n<2) return 0;
    vector<bool> isPrime(n,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;(long long)i*i<n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrime[i]) count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int res=solve(n);
    cout<<res;
    return 0;
}
