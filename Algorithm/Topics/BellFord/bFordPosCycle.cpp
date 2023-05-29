#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];
int d[N];


bool bFordPosCyc(int n,int src){
    for(int i=1;i<=n;i++)d[i]=INF;

    d[src]=0;
    
    for(int i=1;i<=(n+1);i++){
        for(int u=1;u<=n;u++){
            for(auto node:g[u]){
                int v=node.first;
                int w=node.second;

                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    cout<<i<<endl;
                    if(i==n+1){
                        return true;
                    }

                }

            }
        }
    }

    return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        //de-comment if undirected
        //g[b].push_back({a,w});
    }


    if(bFordPosCyc(n,1))cout<<"Has positive cycle"<<endl;
    else cout<<"Doesn't have Positive cycle"<<endl;
    
    return 0;
}

/*

4 4
3 1 2
1 2 3
2 3 -1
2 4 2

*/
