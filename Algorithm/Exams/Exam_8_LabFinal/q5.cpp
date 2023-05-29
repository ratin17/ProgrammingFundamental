#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e3;
const int INF=INT_MAX;

int dp[N][N];
int maze[N][N];
int n,m;

int corns(int x,int y){
    //cout<<x<<" "<<y<<endl;

    if(x==n&&y==1)return maze[x][y];

    if(dp[x][y]!=INF)return dp[x][y];

    int ans1=0,ans2=0;

    if(y-1>0)ans1=corns(x,y-1)+maze[x][y];
    if(x+1<=n)ans2=corns(x+1,y)+maze[x][y];

    dp[x][y]=max(ans1,ans2);

    return dp[x][y];
}



int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=INF;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<4;j++){
            cin>>maze[i][j];
        }
    }

    // cout<<maze[1][m]<<endl;
    // cout<<maze[n][1]<<endl;


    cout<<corns(1,m)<<endl;


    return 0;
}


/*

2 3
3 2 4
1 5 0 

*/