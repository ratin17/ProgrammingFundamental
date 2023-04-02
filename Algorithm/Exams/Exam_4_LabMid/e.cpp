// problem link - https://cses.fi/problemset/task/1192

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
Output -> 3
while there exists an empty cell
    - find an empty unvisited cell
    - run bfs() from that cell
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2002;

char maze[N][N];
int visited[N][N];
pair<int,int> pre[N][N];
int n, m;

pair<int,int>src;
pair<int,int>dest;


int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool is_inside(pair<int, int>coord) {
    int x = coord.first;
    int y = coord.second;

    if(x >= 0 && x < n && y >= 0 &&  y < m) {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int>coord) {
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y]=='.' || maze[x][y]=='@') {
        return true;
    }
    return false;
}

void bfs() {

    queue< pair<int, int> >q;
    visited[src.first][src.second] = 1;

    q.push(src);
    bool posbl=false;
    while(!q.empty()) {
        pair<int,int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i = 0 ; i < 4 ; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];


            pair<int,int>adj_node = {new_x, new_y};

            if(is_inside(adj_node) && 
            is_safe(adj_node) 
            && visited[new_x][new_y] == 0) {
                //cout<<new_x<<" "<<new_y<<endl;
                visited[new_x][new_y] = 1;
                pre[new_x][new_y]={x,y};
                if(new_x==dest.first && new_y==dest.second){
                    posbl=true;
                    break;
                }
                q.push(adj_node);

            }
        }
        if(posbl){
            cout<<"Y"<<endl;
            pair<int,int>pr;
            pr=pre[dest.first][dest.second];
            while(true){
                maze[pr.first][pr.second]='+';
                if(pr.first==src.first&&pr.second==src.second){
                    break;
                }
                pr=pre[pr.first][pr.second];
            }

            for(int v=0;v<m;v++){
                for(int w=0;w<m;w++){
                    cout<<maze[v][w];
                }
                cout<<endl;
            }
            return;
        }
    }
    cout<<"N"<<endl;
    return;
}



int main() {

    cin >> n;
    m=n;

    for(int i = 0 ; i < n  ; i++) {
        string input;
        cin>>input;
        for(int j = 0 ; j < m ; j++) {
            maze[i][j]=input[j];

            if(maze[i][j] == 'X'){
                src={i,j};
            }
            if(maze[i][j] == '@'){
                dest={i,j};
            }
        }
    }

    bfs();

   
    
    return 0;
}
