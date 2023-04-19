#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];
int previ[N];
int visited[N]={0};
int d[N]={0};



void dijkstra(int n,int src){

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    d[src]=0;
    //previ[src]=-1;

    priority_queue<pair<int,int>>q;
    priority_queue<pair<int,int>>p;
    q.push({d[src],src});

    while(!q.empty()){

        //simulation
        p=q;
        cout<<"Priority Queue: ";
        while(!p.empty()){
            int t=p.top().second;
            p.pop();
            cout<<t<<"  ";
        }
        cout<<endl;

        pair<int,int>head=q.top();
        q.pop();
        int selected=head.second;

        //simulation
        cout<<"Currently Selected Node: ";
        cout<<selected<<endl;


        //visited[selected]=1;
        for(pair<int,int> node:g[selected]){
            if(d[selected]+node.second<d[node.first]){
                d[node.first]=d[selected]+node.second;
                previ[node.first]=selected;
                q.push({-d[node.first],node.first});
            }
        }

        //simulation
        cout<<"Distance Update: ";
        for(int i=1;i<=n;i++){
            if(d[i]==INF)cout<<"#  ";
            else cout<<d[i]<<"  ";
        }
        cout<<endl<<endl;

    }

    //printing
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
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
        g[b].push_back({a,w});
    }

    dijkstra(n,2);

    return 0;
}

/*
Input:

6 8
1 2 4
2 3 4
1 3 2
3 5 3
3 6 1
3 4 6
5 4 2
6 4 3


*/