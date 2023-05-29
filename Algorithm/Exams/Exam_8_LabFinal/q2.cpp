
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=100;
vector<int>g[N];
int M[N][3];
int visited[N]={0};


int dis(int a,int b,int x,int y){
    int p=(a-x)*(a-x);
    int q=(b-y)*(b-y);
    return sqrt(p+q);
}



void bfs(int src){
   queue<int>q;
   visited[src]=1;

   q.push(src);

   while(!q.empty()){
    int top=q.front();
    q.pop();

    //cout<<top<<" ";
    for(int node:g[top]){
        if(!visited[node]){
            visited[node]=1;
            q.push(node);
        }
    }
   }

}


int main(){
    int nodes,x,y,r;
    cin>>nodes;


    for(int i=1;i<=nodes;i++){
        cin>>M[i][0]>>M[i][1]>>M[i][2];
    }

    //forming graph from coordnates and radius
   for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            if(i!=j){
                if(dis(M[i][0],M[i][1],M[j][0],
                M[j][1])<=(M[i][2]+M[j][2])){
                    g[i].push_back(j);
                }
            }
        }
    }

    
    vector<int>islands;
    for(int i=1;i<=nodes;i++){
        if(!visited[i]){
            islands.push_back(i);
            bfs(i);
        }
    }

    //cout<<endl;
    cout<<islands.size()<<endl;
    

    return 0;
}


/*
Input:

4
1 1 2
3 3 2
-4 4 2
-6 6 2


*/