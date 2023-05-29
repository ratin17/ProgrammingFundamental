
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e3;
const int INF=INT_MAX;

int dp[N][N];

int nums(int n) {
    
    dp[1][0] = dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-2][1];
        dp[i][1] = dp[i-1][0] + dp[i-2][0];
    }
    
    return dp[n][0] + dp[n][1];
}





int main(){
    int n;
    cin>>n;

    cout<<nums(n)*2<<endl;

    return 0;
}


