#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e3+5;
const int M=1e5+5;
const int INF=INT32_MAX;

long long kn[N][M];

int wt;
int wv[N][2];

long long ksack(int n,int w){
    if(n<1)return 0;
    
    if(wv[n][0]>w){
        kn[n][w]=ksack(n-1,w);
        return kn[n][w];
    }

    if(kn[n][w]!=INF)return kn[n][w];

    kn[n][w]=max(wv[n-1][1]+ksack(n-1,w-wv[n-1][0]),ksack(n-1,w));

    return kn[n][w];
}



int main(){

    int n;
    cin>>n>>wt;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            kn[i][j]=INF;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>wv[i][j];
        }
    }

    cout<<ksack(n,wt)<<endl;

    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;


    return 0;
}
