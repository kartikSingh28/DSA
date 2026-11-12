/*
LC 1208 - Get Equal Substrings Within Budget
Changing s[i] into t[i] costs abs(s[i] - t[i]). Return the longest substring of s
that can be turned into the matching substring of t with total cost <= maxCost.
Example: s = "abcd", t = "bcdf", maxCost = 3 -> 3

Idea: each position has its own cost abs(s[i]-t[i]) -> ADD the costs, never multiply.
      longest window with sum of costs <= maxCost.

Test inputs (s t maxCost):
abcd bcdf 3     -> 3
abcd cdef 3     -> 1
abcd acde 0     -> 1
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string &s,string &t,int maxCost){
    int n1=s.length();
    int n2=t.length();

    int curr_sum=0;
    int head=-1,tail=0;
    int ans=0;

    while(tail<n1){
        while(head+1<n1 && (curr_sum+abs(s[head+1]-t[head+1])<=maxCost)){
            head++;
            curr_sum+=abs(s[head]-t[head]);
        }
        ans=max(ans,head-tail+1);
        if(tail<=head){
            curr_sum-=abs(s[tail]-t[tail]);
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return ans;
}

int main(){
    string s,t;
    int maxCost;
    cin>>s>>t>>maxCost;
    int res=solve(s,t,maxCost);
    cout<<res;
    return 0;
}
