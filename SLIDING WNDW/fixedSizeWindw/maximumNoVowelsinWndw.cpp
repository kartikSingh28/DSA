/// find the maximum number of vowels in a substring with lenght k lc 1456
/*
Given a string s and an integer k, return the maximum number of vowel
letters in any substring of s with length k.

Vowel letters in English are: 'a', 'e', 'i', 'o', 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
*/
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char x){
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
        return true;
    }else{
        return false;
    }
}
int solve(string &s,int k){
    int n=s.size();
    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(isVowel(s[i])){
            count++;
        }
        if(i>=k){
            if(isVowel(s[i-k])){
                count--;
            }

        }
        if(i>=k-1){
            ans=max(ans,count);
        }
        return ans;
    }


}

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    int res=solve(s,k);
    cout<<res<<endl;
    return 0;
}