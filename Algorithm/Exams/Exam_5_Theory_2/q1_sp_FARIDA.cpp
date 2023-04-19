#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e6;
const int INF=INT32_MAX;

long dp[N];
int coin[N];

long cMax(int n){
    cout<<n<<endl;
    
    if(n<1)return 0;
    if(n==1 || n==2)return coin[n];
    if(n==3)return coin[1]+coin[3];
    
    if(dp[n]!=INF)return dp[n];

    dp[n]=max({coin[n]+cMax(n-2),coin[n]+cMax(n-3)});

    return dp[n];

}



int main(){
    int t;
    cin>>t;

    for(int k=1;k<=t;k++){
        int n;
        cin>>n;

        for(int i=1;i<=n;i++){
            dp[i]=INF;
        }

        for(int i=1;i<=n;i++){
            cin>>coin[i];
        }
        int a=cMax(n);
        int b=cMax(n-1);
        cout<<"Case "<<k<<": "<<max(a,b)<<endl;
    }
    
    return 0;
}
