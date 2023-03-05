#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int const N=1000000;
int const INF=1e9;
vector<pair<int,int>>g[N];

int d[N]={0};


void dijkstra(int n,int src){

    for(int i=0;i<n;i++)d[i]=INF;
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
            if(max(d[selected],node.second)<d[node.first]){
                d[node.first]=max(d[selected],node.second);
                // previ[node.first]=selected;
                q.push({-1*d[node.first],node.first});
            }
        }
    }

    
    //printing
    for(int i=0;i<n;i++){
        if(d[i]==INF)printf("Impossible\n");
        else printf("%d\n",d[i]);
    }
    
}



int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin>>T;
    for(int x=1;x<=T;x++){
        int n,m,t;
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

        cin>>t;

        printf("Case %d:\n",x);
        dijkstra(n,t);

        for(int z=0;z<n;z++){
            g[z].clear();
        }
    }

    return 0;
}


/*

2

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8
1

5 4
0 1 5
0 1 4
2 1 3
3 4 7
1

------------------

2

5 4
0 1 5
0 1 4
2 1 3
3 4 7
1

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8
1

*/