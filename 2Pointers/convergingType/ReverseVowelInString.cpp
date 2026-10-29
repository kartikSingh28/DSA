/*
Reverse Vowels of a String (LC 345)
Reverse only the vowels (a, e, i, o, u, upper and lower case); every other character stays where it is.
Example: "IceCreAm" -> "AceCreIm"
*/
#include <bits/stdc++.h>
using namespace std;
string solve(string &s){
    int n=s.length();
    set<int> vowels={'A','E','I','O','U','a','e','i','o','u'};
    int i=0,j=n-1;
    while(i<j){
        if(!vowels.count(s[i])){
            i++;
        }else if(!vowels.count(s[j])){
            j--;
        }else{
            swap(s[i],s[j]);
            i++;
            j--;
        }
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