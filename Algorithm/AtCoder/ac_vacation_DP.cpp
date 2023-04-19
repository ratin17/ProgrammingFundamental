#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e6;
const int INF=INT32_MAX;

long d[N][4];
int happy[N][4];
int k;

long fun(int n,int x){
    if(n==1){
        return happy[n][x];
    }

    if(d[n][x]!=INF)return d[n][x];

    int p1,p2;

    if(x==1)p1=2,p2=3;
    else if(x==2)p1=1,p2=3;
    else p1=1,p2=2;

    d[n][x]=happy[n][x]+max(fun(n-1,p1),fun(n-1,p2));

    return d[n][x];
}



int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<4;j++){
            d[i][j]=INF;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<4;j++){
            cin>>happy[i][j];
        }
    }

    cout<<max({fun(n,1),fun(n,2),fun(n,3)})<<endl;

    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;


    return 0;
}
