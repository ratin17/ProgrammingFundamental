#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e6;
const long INF=INT32_MAX;

long d[N];
int h[N];
int k;

long disOfStoneN(int n){

    // cout<<n<<endl;

    if(n==1)return 0;

    if(d[n]!=INF)return d[n];

    //if(n==2)return abs(h[n]-h[n-1]);

    for(int i=1;i<=k && n-i>0;i++){
        d[n]=
        min(disOfStoneN(n-i)+abs(h[n]-h[n-i]),d[n]);
    }
    
    return d[n];
}



int main(){
    int n;
    cin>>n>>k;

    for(int i=1;i<=n;i++)d[i]=INF;

    for(int i=1;i<=n;i++)cin>>h[i];

    cout<<disOfStoneN(n)<<endl;

    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;


    return 0;
}
