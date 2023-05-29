#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    

    dfs(2);

    return 0;
}

/*
5 6
0 1
0 4
4 3
1 3
1 2
3 2

*/