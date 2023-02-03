#include<bits/stdc++.h>
using namespace std;


 int cComponents(vector<vector<int>>graph){

    vector<vector<int>>components;
    int visited[graph.size()]={};


    for(int i=0;i<graph.size();i++){
        vector<int>temp;
        if(!visited[i]){

            // Executing BFS

            queue<int>que;

            que.push(i);
            visited[i]=1;

            while(!que.empty()){

                int head=que.front();
                que.pop();
                //cout<<head<<" ";
                temp.push_back(head);

                for(int node:graph[head]){
                    if(!visited[node]){
                        que.push(node);
                        visited[node]=1;
                    }
                }
            }

        }
        if(temp.size())components.push_back(temp);
    }

    // // Printing each regions/Components

    // for(int i=0;i<components.size();i++){
    //     for(int j=0;j<components[i].size();j++){
    //         cout<<components[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return components.size();
}
 
int main(){
 
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>>g(n);
 
    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c=cComponents(g);
    cout<<"\nTotal Components: "<<c<<endl<<endl;

    return 0;
}


/*
Input
----------------------------------------

    1           0           5
   / \           \          
  /   \           \  
 3-----4           2    
----------------------------------------

6 4
1 3
1 4
3 4
0 2

*/


