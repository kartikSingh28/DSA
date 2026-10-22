/*
LC 1109 - Corporate Flight Bookings

There are n flights numbered 1 to n.
bookings[i] = [first, last, seats] means `seats` seats are booked on every
flight from `first` to `last` (inclusive).
Return an array ans of size n where ans[i] = total seats booked on flight i+1.
Constraints: 1 <= n <= 2*10^4, 1 <= bookings.length <= 2*10^4,
             1 <= first <= last <= n, 1 <= seats <= 10^4

Input:
n m
m lines of: first last seats

Example:
5 3
1 2 10
2 3 20
2 5 25
Output:
10 55 45 25 25
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> &bookings,int n){
    vector<int> partial(n+1,0);
    vector<int> prefix(n,0);
    for(int i=0;i<bookings.size();i++){
        int l=bookings[i][0];
        int r=bookings[i][1];
        l--,r--;
        int s=bookings[i][2];
        partial[l]+=s;
        partial[r+1]-=s;
    }
    prefix[0]=partial[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+partial[i];
    }
    return prefix;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> bookings(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>bookings[i][0]>>bookings[i][1]>>bookings[i][2];
    }
    vector<int> ans=solve(bookings,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
