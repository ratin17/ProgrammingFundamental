#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e6;
const int INF=INT_MAX;

int d[N];
int h[N];

int disOfStoneN(int n){

    // cout<<n<<endl;

    if(n==1)return 0;

    if(d[n]!=INF)return d[n];

    if(n==2)return abs(h[n]-h[n-1]);


    d[n]=
    min(disOfStoneN(n-1)+abs(h[n]-h[n-1]),
    disOfStoneN(n-2)+abs(h[n]-h[n-2]));

    return d[n];
}



int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)d[i]=INF;

    for(int i=1;i<=n;i++)cin>>h[i];

    cout<<disOfStoneN(n)<<endl;

    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;


    return 0;
}
