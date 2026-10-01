/*lc 1358
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca",
"abcab", "abcabc", "bca", "bcab", "bcabc", 
cab", "cabc" and "abc" (again). 

[a]bcabc  [ab]cabc  [abc]abc(1)  [abca]bc(2) [abcab]c(3)  [abcabc](4)
]a[bcabc  a][bcabc  a[b]cabc   a[bc]abc  a[bca]bc(5)  a[bcab]c(6)  a[bcabc](7) 
ab][cabc ab[c]abc ab[ca]bc ab[cab]c(8) ab[cabc](9)  abc][abc abc[a]bc  abc[ab]c  abc[abc](10)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string &s){
    int n=s.size();
    vector<int> freq(128,0);
    int tail=0,head=-1;
    int count=0;
    while(tail<n){
        while(head+1<n && !(freq['a']>=1 && freq['b']>=1 && freq['c']>=1)){
            head++;
            freq[s[head]]++;
        }
        if(freq['a']>=1 && freq['b']>=1 && freq['c']>=1){
            count+=(n-head);
        }
        if(tail<=head){
            freq[s[tail]]--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return count;
}

int main(){
    string s;
    cin>>s;
    int res=solve(s);
    cout<<res<<endl;
    return 0;
}