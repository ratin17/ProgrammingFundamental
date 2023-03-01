#include<bits/stdc++.h>
using namespace std;



bool isBidirectional(vector<vector<int>>graph){
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(graph[i][j]){
                if(graph[j][i]!=1)return false;
            }
        }
    }
    return true;
}



int main(){
 
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m, vector<int> (m, 0));
 
    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        g[u][v]=1;
    }


    if(isBidirectional(g))cout<<"Bi-directionoal"<<endl;
    else cout<<"Not Bi-directionoal"<<endl;


 
    return 0;
}


/*
Input


3 5
0 2
2 0
2 1
1 2
0 1


*/
