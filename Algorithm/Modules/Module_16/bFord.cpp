#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];
int previ[N];
int visited[N]={0};
int d[N];


string BfordPath(int start,int node,int count){

    if(node==start){
        //prints no of nodes in path
        //cout<<count+1<<endl;
        return to_string(node);
    }

    return
    BfordPath(start,previ[node],count+1)+" "+to_string(node);
}


void bFord(int n,int src,int dest){

    for(int i=1;i<=n;i++)d[i]=INF;
    d[src]=0;
    previ[src]=-1;

    bool negCycle=false;
    for(int i=1;i<=n;i++){
        for(int u=1;u<=n;u++){
            for(auto node:g[u]){
                int v=node.first;
                int w=node.second;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    previ[v]=u;
                    if(i==n)
                        negCycle=true;
                }
            }
        }
    }

    //printing
    string s=BfordPath(src,dest,0);
    cout<<s<<endl;
    if(negCycle)cout<<"Neg Cycle Exists\n";
    else cout<<"No Neg Cycle\n";
    for(int i=1;i<=n;i++){
        if(d[i]==INF)cout<<"# ";
        else cout<<d[i]<<" ";
    }
    cout<<endl;

}


int main(){
    int n,m;
    //Enter number of nodes and edges
    cin>>n>>m;
    int a,b,w;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        //de-comment if undirected
        //g[b].push_back({a,w});
    }

    bFord(n,1,2);
    

    return 0;
}

/*

4 5
1 3 0
1 2 1
1 4 99
4 2 -300
2 3 1

*/
