#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>EdgeWeight;

class Graph{
    
    int V;
    list <EdgeWeight> * adj;

public:
    Graph(int v){
        V=v;
        adj=new list <EdgeWeight>[V];
        //cout<<"inside Graph cons"<<endl;
    }

    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        //cout<<"inside at edge"<<endl;
    }

    void printNeighbours(int vert){
        for(auto i=adj[vert].begin();i!=adj[vert].end();i++){
            cout<<"("<<(*i).first<<" , "<<(*i).second<<")";
            if((++i) !=adj[vert].end()){
                cout<<" -> ";
            }
            --i;
        }
        cout<<endl;
    }

};

int main(){
    int V,e;
    cin>>V>>e;
    Graph g=Graph(V);
    int u,v,w;
    while(e--){
        cin>>u>>v>>w;
        cout<<u<<v<<w<<endl;
        g.addEdge(u,v,w);
    }

    g.printNeighbours(0);
}

/*

4 5
0 1 3
0 3 6
0 2 4
2 1 1
1 3 9

*/