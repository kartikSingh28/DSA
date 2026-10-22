/*
LC 1094 - Car Pooling

A car with `capacity` empty seats drives only east (locations 0 to 1000).
trips[i] = [numPassengers, from, to]: numPassengers get on at `from` and
get off at `to`. Return true if you can pick up and drop off everyone
without ever having more than `capacity` people in the car.
Constraints: 1 <= trips.length <= 1000, 1 <= numPassengers <= 100,
             0 <= from < to <= 1000, 1 <= capacity <= 10^5

Input:
m capacity
m lines of: numPassengers from to

Example:
2 4
2 1 5
3 3 7
Output: false     (with capacity 5 -> true)
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> &trips,int capacity){
    int n=1001;
    vector<int> partial(n+1,0);
    vector<int> prefix(n,0);
    for(int i=0;i<trips.size();i++){
        int numPasseger=trips[i][0];
        int l=trips[i][1];
        int r=trips[i][2];
        partial[l]+=numPasseger;
        partial[r]-=numPasseger;
    }
    prefix[0]=partial[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+partial[i];
    }
    for(int i=0;i<prefix.size();i++){
        if(prefix[i]>capacity){
            return false;
        }
    }
    return true;

}

int main(){
    int m,capacity;
    cin>>m>>capacity;
    vector<vector<int>> trips(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>trips[i][0]>>trips[i][1]>>trips[i][2];
    }
    bool ans=solve(trips,capacity);
    cout<<(ans?"true":"false")<<endl;
    return 0;
}
