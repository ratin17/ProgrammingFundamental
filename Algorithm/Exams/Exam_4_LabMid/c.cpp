#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1000000;
int const INF=1e9;
vector<int>g[N];
//int previ[N];
int visited[N]={0};
int d[N]={0};

 


int main(){
    int n,k;
    //Enter number of nodes and edges
    cin>>n;
    cin>>k;

    int a,b,c;
    //Enter Edges: src --> dest
    while(k--){
        cin>>a;

        if(a==1){
            cin>>b>>c;
            g[b].push_back(c);
            //de-comment if undirected
            g[c].push_back(b);

        }
        else if(a==2){
            cin>>b;
            int s=g[b].size();
            for(int node:g[b])cout<<node<<" ";
            cout<<endl;
        }
        
    }

    

    return 0;
}

/*

6 9
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
3 5 2
4 5 3
4 6 1
5 6 2

*/