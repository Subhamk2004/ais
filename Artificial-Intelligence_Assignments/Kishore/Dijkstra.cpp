#include <bits/stdc++.h>
using namespace std;
//  t.c- O(E * log V)
// Dijkstra's Algorithm
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    set<pair<int, int>> st; // {distance, node}
    st.insert({0, src});
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);
            // make sure to remove the node from the set
        for (auto edge : adj[node]) {
            int adjNode = edge.first;
            int edgeWeight = edge.second;

            if (distance + edgeWeight < dist[adjNode]) {
               
                
                dist[adjNode] = distance + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V); // adjacency list

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // if undirected graph
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> distances = dijkstra(V, adj, src);

    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance: " << distances[i] << "\n";
    }

    return 0;
}
