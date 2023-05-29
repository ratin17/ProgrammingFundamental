#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e6;
const int INF=INT32_MAX;
int dp[N]={INF};

int n;


int brute(int id) {
    if(id >= n) {
        return 0;
    }

    if(dp[id]!=INF)return dp[id];


    dp[id] = max({
        1 + brute(id + 1),
        2 + brute(id + 3),
        3 + brute(id + 5)
    });

    return dp[id];
}

int tabulation(){

    for(int i=n;i<=n+5;i++){
        dp[i]=0;
    }

    for(int i=n;i>=0;i--){
        dp[i] = max({
            1 + dp[i+1],
            2 + dp[i+3],
            3 + dp[i+5],
        });
    }

    return dp[0];
}
