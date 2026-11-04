/*
Merge Sorted Array (LC 88)
nums1 (size m) and nums2 (size n) are both sorted. Merge them into one sorted array.
(LeetCode version: nums1 has extra space at the end and the merge must happen inside nums1.)
Example: nums1=[1,2,3], nums2=[2,5,6] -> [1,2,2,3,5,6]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int m,vector<int> &nums1,int n,vector<int> &nums2){
    vector<int> temp(m+n);
    int i=0,j=0,k=0;

    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            temp[k]=nums1[i];
            i++;
            k++;
        }else{
            temp[k]=nums2[j];
            j++;
            k++;
        }
    }
    while(i<m){
        temp[k]=nums1[i];
        i++;
        k++;
    }
    while(j<n){
        temp[k]=nums2[i];
        j++;
        k++;
    }
    nums1=temp;
    return nums1;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    for(int i=0;i<m;i++)cin>>nums1[i];
    for(int i=0;i<n;i++)cin>>nums2[i];

    vector<int> res=solve(m,nums1,n,nums2);
    for(auto x:res)cout<<x<<" ";
    return 0;
}