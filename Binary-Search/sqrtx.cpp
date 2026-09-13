// if 0<=x<10^18 find sqare root of x
//so we will index of first 0, and# make  such that if y*y>x then 1 else 0

#include <bits/stdc++.h>
using namespace std;
using lli=long long;

lli check(lli y,lli x){
    if(y*y>x) return 1;
    else return 0;

}

int main(){
    return 0;
    lli x;
    cin>>x;
    lli lo=0,hi=x;// so take hi=1e9 for dont overflow
    lli ans=hi+1;// assumption 1 lies outside the range

    while(lo<=hi){
        lli mid=lo+(hi-lo)/2;
        if(check(mid,x)==0){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<(ans-1)<<endl;
    return 0;
}

