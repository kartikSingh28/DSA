/*
Sort Array By Parity II (LC 922)
Half the numbers are even, half are odd. Rearrange in-place so every even index holds an
even number and every odd index holds an odd number (any valid answer is fine).
Example: [4,2,5,7] -> [4,5,2,7]

Old notes:
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    return 0;
}
o,e
0,1,2,3
[4,2,5,7]
[]
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &nums){
    int n=nums.size();
    int odd=1,even=0;
    while(odd<n && even<n){
        if(nums[even]%2==0){
            even+=2;
        }else if(nums[odd]%2!=0){
            odd+=2;
        }else{
            swap(nums[even],nums[odd]);
            even+=2;
            odd+=2;
        }
    }
    return nums;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int> res=solve(nums);
    for(auto x:res)cout<<x<<" ";
    return 0;
}