#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    int V;
    list <int> * adj;

public:
    Graph(int v){
        V=v;
        adj=new list<int>[V];
        //cout<<"inside Graph cons"<<endl;
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        //cout<<"inside at edge"<<endl;
    }

    int printNeighbours(int vert){
        int count =0;
        for(auto i=adj[vert].begin();i!=adj[vert].end();i++){
            count++;
        }
        return count;
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
    cout<<g.printNeighbours(k)<<endl;
}

/*

4 5
0 1
0 3
0 2
2 1
1 3


*/