#include<bits/stdc++.h>
using namespace std;

vector<int> nodes[1000];
bool vis[1000];

void bfs(int src,int L){
    queue<pair<int,int>>q;
    vis[src]=true;
    q.push({src,0});
    while(!q.empty()){
        pair<int,int> parent=q.front();
        q.pop();
        if(parent.second==L){
            cout<<parent.first<<" ";
        }
        for(int i=0;i<nodes[parent.first].size();i++){
            int children=nodes[parent.first] [i];
            if(vis[children]!=true){
                vis[children]=true;
                q.push({children,parent.second+1});
            }
        }
    }

}
int main(){
    int N,E;
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int A,B;
        cin>>A>>B;
        nodes[A].push_back(B);
        nodes[B].push_back(A);
    }
    memset(vis,false,sizeof(vis));
    int L;
    cin>>L;
    bfs(0,L);
}