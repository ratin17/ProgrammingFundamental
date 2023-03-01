#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];

 

int dijkstra(int n,int src,int dest){
    int visited[n]={0};
    int d[n];

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    d[src]=0;


    for(int i=1;i<=n;i++){

        int selected=-1;
        for(int j=1;j<=n;j++){
            if(visited[j]==1)continue;
            if(selected==-1||d[j]<d[selected]){
                selected=j;
            }
        }

        //cout<<selected<<endl;
        visited[selected]=1;
        for(pair<int,int> node:g[selected]){
            if(d[selected]+node.second<d[node.first]){
                d[node.first]=d[selected]+node.second;
            }
        }
    }


    //printing
    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;

    //path printing
    // int path=n;
    // while(path!=-1){
    //     cout<<path<<" <- ";
    //     path=previ[path];
    // }
    // cout<<endl;

    if(d[dest]==INF)return -1;
    return d[dest];
}

int main(){
    int n,m,q;
    //Enter number of nodes and edges
    cin>>n>>m>>q;
    int a,b,w;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        //de-comment if undirected
        g[b].push_back({a,w});
    }
    int s,d;
    for(int i=1;i<=q;i++){
        cin>>s>>d;
        cout<<dijkstra(n,s,d)<<endl;
    }

    return 0;
}

/*

4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

*/