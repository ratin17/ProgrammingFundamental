#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e3;
const int INF=INT32_MAX;

long dp[N][N];
int b[N][N];
long n,r;

long ban(int x,int y){

    //cout<<"("<<x<<","<<y<<")"<<endl;

    if(x==1&&y==1)return b[x][y];

    if(dp[x][y]!=INF)return dp[x][y];

    if(x>n){
        dp[x][y]=b[x][y]+max({ban(x-1,y),ban(x-1,y+1)});
    }
    else{
        if(y==1)dp[x][y]=b[x][y]+ban(x-1,y);
        else if(y==x)dp[x][y]=b[x][y]+ban(x-1,y-1);
        else dp[x][y]=b[x][y]+max({ban(x-1,y),ban(x-1,y-1)});
    }

    return dp[x][y];
}



int main(){
    int t;
    cin>>t;

    for(int k=1;k<=t;k++){
        
        cin>>n;
        r=2*n-1;

        for(int i=0;i<=r;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=INF;
            }
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cin>>b[i][j];
            }
        }
        for(int i=n+1,l=n-1;l>0;i++,l--){
            for(int j=1;j<=l;j++){
                cin>>b[i][j];
            }
        }

        //printing input
        // cout<<endl;
        // for(int i=0;i<=r;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        cout<<"Case "<<k<<": "<<ban(r,1)<<endl;





        
    }
    
    return 0;
}
