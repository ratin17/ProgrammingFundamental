#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e5;
const long INF=INT32_MAX;

long dp[N];


int sqrNum(int n){
    if(n==0)return 0;

    if(dp[n]!=INF){
        return dp[n];
    }
    int ans=INT_MAX;

    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+sqrNum(n-temp));
    }
    return dp[n]=ans;
}




int main(){
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        dp[i]=INF;
    }

    cout<<sqrNum(n)<<endl;

    return 0;
}
