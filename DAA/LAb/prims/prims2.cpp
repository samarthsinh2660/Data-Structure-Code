#include <bits/stdc++.h>
using namespace std;

    
int spanningTree(int V, vector<vector<pair<int, int>>> &adj) {
    // Min-heap to store {weight, node} pairs.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0); // To track visited nodes.
    pq.push({0, 0}); // Starting with node 0 and weight 0.
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue; // Skip if already included in MST.

        // Include the node in MST.
        vis[node] = 1;
        sum += wt;

        // Traverse all adjacent nodes.
        for (auto &adjPair : adj[node]) {
            int adjNode = adjPair.first;
            int edgeWeight = adjPair.second;
            if (!vis[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}
    };

    // Creating the adjacency list.
    vector<vector<pair<int, int>>> adj(V);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << sum << endl;

    return 0;
}
