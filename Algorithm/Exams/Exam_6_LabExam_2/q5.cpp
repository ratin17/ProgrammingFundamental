#include<bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int longestPathDAG(vector<vector<int>> &graph, int start, int end) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    vector<int> dist(n, -INF);
    dist[start] = 0;
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
            if (dist[u] != -INF && dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[end];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int start, end;
    cin >> start >> end;
    int longestPath = longestPathDAG(graph, start, end);
    cout << longestPath << endl;
    return 0;
}
