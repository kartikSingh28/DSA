#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int> &nums,int MAX,int k){
    int n=nums.size();
    int tail=0,head=-1;
    int max_cnt=0;
    vector<int> freq(10100,0);
    int ans=0;
    while(tail<n){
        while(head+1<n && (max_cnt<k || freq[nums[head+1]]!=0)){
            head++;
            if(nums[head]==MAX){
                max_cnt++;
            }
            freq[nums[head]]++;
        }
        ans+=(head-tail+1);
        if(tail<=head){
            freq[nums[tail]]--;
            if(nums[tail]==MAX){
                max_cnt--;
            }
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
        return ans;
    }
}

int main(){
    return 0;
}