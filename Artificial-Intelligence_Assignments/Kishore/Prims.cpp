#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
// t.c- O(E * log V)
// S.c - O(V + E)
void primMST(int V, vector<vector<pair<int, int>>>& adj) {
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0); // visited array to track included vertices
    // Initialize the priority queue with the first vertex (0)
    // {weight, node}
    set<pair<int, int>> st;
    vector<int> parent(V, -1);
    st.insert({0, 0});
    int sum = 0;
    while (!st.empty()) {
        auto it = *(st.begin());
        st.erase(st.begin());
        int node = it.second;
        int wt = it.first;
        if (vis[node]) continue;
        sum += wt;
        vis[node] = 1; // yha jake mark krengey finally isme dhyan se ki this is visited.
        for (auto it : adj[node]) {
            int edgeWeight = it.first;
            int adjNode = it.second;
            parent[adjNode] = node;
            if (!vis[adjNode]) {
                st.insert({edgeWeight, adjNode});
            }
        }
    }
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i <<endl;
       
    }
    cout << "Minimum Spanning Tree Weight: " << sum << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter edges in the format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // undirected
    }
    primMST(V, adj);
    return 0;
}

// typedef pair<int, int> pii; // (weight, node)

// void primMST(int V, vector<vector<pii>>& adj) {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;

//     vector<bool> inMST(V, false); // track if vertex is included in MST
//     vector<int> key(V, INT_MAX);  // minimum weight edge to a vertex
//     vector<int> parent(V, -1);    // store MST

//     key[0] = 0;
//     pq.push({0, 0}); // (weight, vertex)

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         if (inMST[u]) continue;

//         inMST[u] = true;

//         for (auto [weight, v] : adj[u]) {
//             if (!inMST[v] && weight < key[v]) {
//                 key[v] = weight;
//                 pq.push({weight, v});
//                 parent[v] = u;
//             }
//         }
//     }

//     // Print MST
//     cout << "Edges in MST:\n";
//     int totalCost = 0;
//     for (int i = 1; i < V; i++) {
//         cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
//         totalCost += key[i];
//     }
//     cout << "Total weight of MST: " << totalCost << endl;
// }

// int main() {
//     int V, E;
//     cout << "Enter number of vertices and edges: ";
//     cin >> V >> E;

//     vector<vector<pii>> adj(V);

//     cout << "Enter edges in the format: u v weight\n";
//     for (int i = 0; i < E; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({w, v});
//         adj[v].push_back({w, u}); // undirected
//     }

//     primMST(V, adj);

//     return 0;
// }
