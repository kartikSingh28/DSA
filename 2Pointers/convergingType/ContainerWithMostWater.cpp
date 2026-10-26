/*
Container With Most Water (LC 11)
Pick two lines; area = width * shorter height. Return the max area.
Example: [1,8,6,2,5,4,8,3,7] -> 49
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &height){
    int n=height.size();
    int i=0,j=n-1;
    int maxArea=0;
    while(i<j){
        int minH=min(height[i],height[j]);
        maxArea=max(maxArea,(j-i)*minH);
        if(height[i]>height[j]){// choti height hi leni so choti m v bada height lena so minH max ho ske kuki widdth dec ho rhi
            j--;
        }else{
            i++;
        }
    }
    return maxArea;

}

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++)cin>>height[i];
    int res=solve(height);
    cout<<res;
    return 0;
}