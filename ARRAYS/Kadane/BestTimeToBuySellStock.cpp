/*
LC 121 - Best Time to Buy and Sell Stock
Buy on one day, sell on a LATER day. Return the max profit (0 if no profit is possible).
Example: [7,1,5,3,6,4] -> 5   (buy at 1, sell at 6)

*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices){
    int n=prices.size();
    int minPrice=prices[0];
    int profit=0;
    for(int i=1;i<n;i++){
        if(prices[i]<minPrice){
            minPrice=prices[i];
        }
        profit=max(profit,prices[i]-minPrice);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)cin>>prices[i];
    int res=solve(prices);
    cout<<res;
    return 0;
}
