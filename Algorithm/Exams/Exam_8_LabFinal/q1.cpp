
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=100;
vector<pair<int,int>>g[N];
int M[N][N];



int main(){
    int nodes,edges,u,v,w;
    cin>>nodes>>edges;

    //input adj list
    for(int i=1;i<=edges;i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }

    //converstion from list to matrix
    for(int i=1;i<=nodes;i++){
        for(auto node:g[i]){
            M[i][node.first]=node.second;
        }
    }

    //print adj matrix
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

    
    

    return 0;
}


/*
Input:

7 7
1 3 4
3 4 2
3 5 1
5 6 2
4 2 8
4 7 5
2 7 9


*/