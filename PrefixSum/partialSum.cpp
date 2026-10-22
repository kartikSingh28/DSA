/* there are q queries of the form
+L R X-> add X to all the index in range L to R
after all the queries find the final array

+ 2 4 1   [0,0,0,0,0,0] -> [0,0,1,1,1,0] ->
+ 1 5 3 ->  [0,3,4,4,4,3]
+ 0 2 2 -> [2,5,6,4,4,3]
brute force O(N.Q)  for q queries

partial sum Technique
take a array P of same size intialize with 0
now for range L-R and the no we have to add X P[L]+=X ,P[R+1]-=X it cancels the contribution and 
make it happ4n till L to R

now build the prfix array out of this P array complexity O(N)
therefore total complexity O(N+Q)
*/
#include <bits/stdc++.h>
using namespace std;


vector<long long> solve(vector<int> &nums){
    int n=nums.size();
    int q;
    cin>>q;
    vector<long long> partial(n+1,0);
    vector<long long> prefix(n,0);
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        partial[l]+=x;
        partial[r+1]-=x;
    }
    prefix[0]=partial[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+partial[i];//O(n)
    }
    for(int i=0;i<n;i++){
        prefix[i]+=nums[i];
    }
    return prefix;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<long long> res=solve(nums);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
