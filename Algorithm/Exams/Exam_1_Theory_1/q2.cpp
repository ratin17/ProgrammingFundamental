
#include<bits/stdc++.h>
using namespace std;

 
int main(){
 
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(m, vector<int> (m, 0));
 
    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        graph[u][v]=1;
    }


    cout<<endl<<"Before Trimming:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



    int trim=0;
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(graph[i][j]){
                if(!graph[j][i]){
                    trim++;
                    graph[i][j]=0;
                }
            }
        }
    }



    cout<<"Number of edges removed : "<<trim<<endl;



    cout<<endl<<"After Trimming:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;    

 
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

