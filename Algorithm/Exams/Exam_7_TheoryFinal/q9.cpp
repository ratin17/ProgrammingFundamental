

#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5 + 5;

long long dp[N][M];
float frac[N], profit[N];

long long knapsack(int n, int cap) {

    if(n == 0) {
        return 0;
    }
    
    if(dp[n][cap] != -1) {
        return dp[n][cap];
    }



    if(cap < (int)(frac[n]*100)) {
        long long ans = knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    long long ans1 = profit[n] + 
    knapsack(n - 1, cap - (int)(frac[n]*100) );

    long long ans2 = knapsack(n-1, cap);

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;

    return ans;
}

int main() {
    int n, cap;
    cin >> n;

    cap=100;

    for(int i = 1 ; i <= n ; i++) {
        cin >> frac[i] >> profit[i];
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= cap ; j++) {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, cap) << endl;
    return 0;

}