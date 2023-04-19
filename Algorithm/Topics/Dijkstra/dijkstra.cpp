#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];
//int previ[N];
int visited[N]={0};
int d[N]={0};

 

void dijkstra(int n,int src){

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    d[src]=0;
    //int pr=-1;

    for(int i=1;i<=n;i++){

        int selected=-1;
        for(int j=1;j<=n;j++){
            if(visited[j])continue;
            if(selected==-1||d[j]<d[selected]){
                selected=j;
            }
        }

        //previ[selected]=pr;
        //pr=selected;

        visited[selected]=1;
        for(pair<int,int> node:g[selected]){
            if(d[selected]+node.second<d[node.first]){
                d[node.first]=d[selected]+node.second;
            }
        }
    }

    //printing
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
    //path printing
    // int path=n;
    // while(path!=-1){
    //     cout<<path<<" <- ";
    //     path=previ[path];
    // }
    // cout<<endl;
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
        g[b].push_back({a,w});
    }

    dijkstra(n,1);

    return 0;
}

/*

6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2

*/