#include <bits/stdc++.h>

using namespace std;

// Recursive DFS
void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

// Iterative BFS
void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter each edge as two vertex indices (0-based):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // You can choose any start vertex; here we pick 0
    int start = 0;

    // DFS
    vector<bool> visited(V, false);
    cout << "\nDepth-First Search starting from vertex " << start << ":\n";
    dfs(start, adj, visited);

    // BFS
    fill(visited.begin(), visited.end(), false);
    cout << "\n\nBreadth-First Search starting from vertex " << start << ":\n";
    bfs(start, adj, visited);

    cout << "\n";
    return 0;
}
