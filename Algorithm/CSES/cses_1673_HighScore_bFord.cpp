#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000;
int const INF=1e9;
vector<pair<int,int>>g[N];
int previ[N];
int visited[N]={0};
long long d[N];



void bFord(int n,int src,int dest){

    for(int i=1;i<=n;i++)d[i]=INF;
    d[src]=0;
    previ[src]=-1;

    bool negCycle=false;
    //cycleNodeCoount
    int cNc=0,lRn;
    for(int i=1;i<=n;i++){
        for(int u=1;u<=n;u++){
            for(auto node:g[u]){
                int v=node.first;
                int w=node.second;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    previ[v]=u;
                    if(i==n){
                        negCycle=true;
                        cNc++;
                        lRn=v;
                    }
                }
            }
        }
    }

    if(negCycle)cout<<-1<<endl;
    else cout<<d[dest]*-1<<endl;
    


    

}


int main(){
    int n,m;
    //Enter number of nodes and edges
    cin>>n>>m;
    int a,b,w;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back({b,w*-1});
        //de-comment if undirected
        //g[b].push_back({a,w});
    }

    bFord(n,1,n);
    

    return 0;
}

/*

--------------------
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
-----------

*/
