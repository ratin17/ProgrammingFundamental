#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int count;
    int V;
    list <int> * adj;

    queue<int>q;


    Graph(int v){
        V=v;
        adj=new list<int>[V];
        count=0;
        //cout<<"inside Graph cons"<<endl;
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        //cout<<"inside at edge"<<endl;
    }

    void counttNeighbours(int vert){
        count++;
        //cout<<"Called : "<<vert<<" c: "<<count<<endl;
        for(auto i=adj[vert].begin();i!=adj[vert].end();i++){
            q.push((*i));
        }
    }

};

int main(){
    int V,e,k;
    cin>>V>>e;
    Graph g=Graph(V);
    int u,v;
    while(e--){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cin>>k;

    bool visited[V]={false};
    g.q.push(k);

    int t;

    while(!g.q.empty()){
        t=g.q.front();
        g.q.pop();
        if(!visited[t]){
            visited[t]=true;
            
            g.counttNeighbours(t);
        }
    }

    cout<<g.count-1<<endl;
}

/*

6 5
0 5
0 2
0 3
1 4
2 5


*/