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



int main(){

    int n;
    cin>>n>>wt;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            kn[i][j]=INF;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            cin>>wv[i][j];
        }
    }

    for(int i=0;i<=wt;i++){
        kn[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=wt;j++){

            if(j<wv[i][0]){
                kn[i][j]=kn[i-1][j];
            }
            else{
                kn[i][j]=max(
                    wv[i][1]+kn[i-1][j-wv[i][0]],
                    kn[i-1][j]
                );
            }
            
        }
    }

    cout<<kn[n][wt]<<endl;

    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;


    return 0;
}
