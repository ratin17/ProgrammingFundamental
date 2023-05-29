#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e3;
const int INF=INT_MAX;

int dp[N][N];

int ways(int n) {
    
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
    }
    
    return dp[n][0] + dp[n][1] + dp[n][2];
}



int main(){
    int n;
    cin>>n;

    cout<<ways(n)<<endl;

    return 0;
}

