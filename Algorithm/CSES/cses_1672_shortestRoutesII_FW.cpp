#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=10000;
long long const INF=1e18;
long long g[N][N];

void fWarsh(int n){

    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                g[u][v]=min(g[u][v],g[u][k]+g[k][v]);
            }
        }
    }

    //printing

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(g[i][j]==INF)cout<<"# ";
    //         else cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}



int main(){
    int n,m,q;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=INF;
        }
    }

    // input
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        if(w<g[u][v])g[u][v]=w;
        //de-cooment if undirected
        if(w<g[v][u])g[v][u]=w;
    }

    

    fWarsh(n);

    
    
    while(q--){
        cin>>u>>v;
        if(g[u][v]==INF)
        cout<<-1<<endl;
        else cout<<g[u][v]<<endl;
    }

    return 0;
}

/*
Input

-------------------

4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2


-------------------


*/