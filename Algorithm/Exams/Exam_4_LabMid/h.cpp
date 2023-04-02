#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];
int visited[N]={0};
int d[N]={0};
int w[N];





int dijkstra(int n,int src,int dest){

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    d[src]=0;
    //previ[src]=-1;

    priority_queue<pair<int,int>>q;
    q.push({d[src],src});

    while(!q.empty()){

        pair<int,int>head=q.top();
        q.pop();
        int selected=head.second;


        //visited[selected]=1;
        for(pair<int,int> node:g[selected]){
            if(d[selected]+node.second<d[node.first]){
                d[node.first]=d[selected]+node.second;
                q.push({d[node.first],node.first});
            }
        }
    }

    //printing
    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    // cout<<endl;
    
    if(d[dest]==INF)return -1;
    else return d[dest];
}

int main(){
    int n,m;
    //Enter number of nodes and edges
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    int a,b;

    cin>>m;
    //Enter Edges: src --> dest
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back({b,w[a]});
        //de-comment if undirected
        g[b].push_back({a,w[b]});
    }

    cout<<dijkstra(n,1,n)<<endl;

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