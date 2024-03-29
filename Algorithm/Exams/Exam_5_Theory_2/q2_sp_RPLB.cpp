#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back


int n,W,wt[1001];
int dp[1001][1001];


int solve(int i,int w){
    cout<<i<<" "<<w<<endl;
	if(i>n)
	   return w;
	if (dp[i][w]!=-1)
	  return dp[i][w];
	  if((wt[i]+w)<=W)
	dp[i][w]=max(solve(i+2,w+wt[i]),solve(i+1,w));
	else
	 dp[i][w]=solve(i+1,w);
	 return dp[i][w];
}


int main(){
    int t;
    scanf("%d",&t);
    FOR(j,1,t+1){
		scanf("%d %d",&n,&W);
		FOR(i,1,n+1){
			scanf("%d",&wt[i]);
		}
		 memset(dp,-1,sizeof dp);
		printf("Scenario #%d: %d\n",j,solve(1,0));
	}
}