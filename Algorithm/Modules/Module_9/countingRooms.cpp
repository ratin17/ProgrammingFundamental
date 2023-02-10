/*

5 8
########
#.A#...#
#.##.###
#......#
########

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int const N=1050;
int visited[N][N]={};
int Ncount=0;
char g[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};


void dfs(int x,int y,int n,int m){
    
    visited[x][y]=1;

    //cout<<"("<<sx<<","<<sy<<")";
    // std::chrono::milliseconds sleepDuration(2000);
    // std::this_thread::sleep_for(sleepDuration);

    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;

        if(nx>-1 && ny>-1 && nx<n && ny<m && 
        visited[nx][ny]==0 && g[nx][ny]=='.'){  
            dfs(nx,ny,n,m);
        }
    }
}

int main(){
    int m,n;
    cin>>n>>m;

    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin>>g[i][j];
        }
    }

    int rooms=0;
    for(int i = 0 ; i < n  ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(g[i][j]=='.'&&!visited[i][j]){
                rooms++;
                dfs(i,j,n,m);
            }
        }
    }

    cout<<rooms<<endl;

    
    return 0;
}

/*

5 8
########
#..#...#
####.#.#
#..#...#
########

*/

