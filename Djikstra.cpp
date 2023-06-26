#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000; // A very large value to represent infinity
const int MAXN = 1000; // Maximum number of nodes in the graph

vector<pair<int,int>> adj[MAXN]; // Adjacency list to store the graph
int dist[MAXN]; // Array to store the shortest distance to each node

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Priority queue to store nodes to visit
    fill(dist, dist+MAXN, INF); // Initialize all distances to infinity
    dist[start] = 0; // Set the starting node's distance to 0
    pq.push(make_pair(0, start)); // Push the starting node to the queue

    while (!pq.empty()) {
        pair<int,int> curr = pq.top();
        pq.pop();
        int d = curr.first;
        int u = curr.second;
        if (d > dist[u]) continue; // Skip if we've already processed a shorter path to this node
        for (pair<int,int> edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) { // If this path is shorter than the current best path to node v
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v)); // Add this node to the queue to be processed
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dijkstra(s);
    cout << "Shortest path from " << s << " to " << t << " is " << dist[t] << endl;
    return 0;
}
