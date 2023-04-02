/*
Problem:

Between some villages of Vasyuki district there are buses routes. As the passenger 
traffic is not very large, the buses run only a few times a day.

Maria Ivanovna wants to get from the village d to the village v as soon as possible 
(it is assumed that at time 0 she is in the village d).

Input
First given the total number of villages n (1 ≤ n ≤ 100), d and v, then the number of bus 
lines r (0 ≤ r ≤ 10000). Then given the description of bus trips. Each route is given by the 
number of the starting village, time of departure, the destination village and the arrival 
time (all times are integers from 0 to 10000). If at time t the passenger arrives in the 
village, he can leave it at any time, starting from t.

Output
Print the minimum time when Maria Ivanovna can reach the village v. If she fails with these bus 
trips to get from d to v, output -1.

input:

3
1 3
4
1 0 2 5
1 1 2 3
2 3 3 5
1 1 3 10

output:
5

*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, pair<int, int>>>> graph;
vector<int> mat;

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    mat[start] = 0;

    while (!pq.empty()) {
        int village = pq.top(). second;
        int arrival = pq.top(). first;
        pq.pop();

        if (arrival > mat[village]) {
            continue;
        }

        for (int i = 0; i < graph[village].size(); i++) {
            int to = graph[village][i].first;
            int departure = graph[village][i].second. first;
            int arrival = graph[village][i].second. second;
            if (mat[to] > arrival && mat[village] <= departure) {
                mat[to] = arrival;
                pq. push(make_pair (mat[to], to));
            }
        }
    }

}

int main() {
    int n, d, v, r;
    cin >> n >> d >> v>>r;

    graph.resize(n + 1);
    mat.resize(n + 1, INT_MAX);

    for (int i= 0; i <r; i++) {
        int start, departure, end, arrival;
        cin >> start >> departure >> end >> arrival;
        graph[start].push_back(make_pair(end, make_pair(departure, arrival)));
    }

    dijkstra(d);

    if (mat[v] == INT_MAX) {
        cout << "-1\n";
    }

    else{
        cout << mat[v] << "\n";
    }

    return 0;
}
