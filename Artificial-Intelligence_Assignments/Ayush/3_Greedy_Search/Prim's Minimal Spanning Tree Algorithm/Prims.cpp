// Prim's Minimal Spanning Tree Algorithm

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a weighted edge in graph
struct Edge {
    int dest;
    int weight;
};

// Structure to represent a connected, undirected and weighted graph
class Graph {
private:
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to graph
    void addEdge(int u, int v, int w) {
        // Since the graph is undirected, add edges in both directions
        Edge e1 = {v, w};
        Edge e2 = {u, w};
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    // Function to find MST using Prim's algorithm
    void primMST() {
        // Create a priority queue to store vertices that need to be processed
        // This is where our greedy selection happens - we choose the edge with the smallest weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0; // Starting vertex

        // Create an array for keys and initialize all keys as INFINITE
        vector<int> key(V, INT_MAX);

        // To store parent array which is used to store the MST
        vector<int> parent(V, -1);

        // To track vertices included in MST
        vector<bool> inMST(V, false);

        // Insert source into priority queue and initialize its key as 0
        pq.push(make_pair(0, src));
        key[src] = 0;

        // Loop until priority queue becomes empty
        while (!pq.empty()) {
            // Extract the vertex with minimum key value
            int u = pq.top().second;
            pq.pop();

            // Skip if vertex is already in MST
            if (inMST[u])
                continue;

            inMST[u] = true; // Include vertex in MST

            // Traverse all adjacent vertices of u
            for (auto& edge : adj[u]) {
                // Get vertex label and weight of current adjacent of u
                int v = edge.dest;
                int weight = edge.weight;

                // If v is not in MST and weight of (u,v) is smaller than current key of v
                if (!inMST[v] && weight < key[v]) {
                    // Update key of v
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Print edges of MST and calculate total weight
        int totalWeight = 0;
        cout << "\nEdges in the Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " (weight: ";
            
            // Find the weight of the edge
            int weight = 0;
            for (auto& edge : adj[parent[i]]) {
                if (edge.dest == i) {
                    weight = edge.weight;
                    break;
                }
            }
            
            cout << weight << ")" << endl;
            totalWeight += weight;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    Graph g(V);
    
    cout << "Enter the edges in format <source> <destination> <weight>:" << endl;
    cout << "(Note: Vertices are numbered from 0 to " << V-1 << ")" << endl;
    
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Validate input
        if(u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex! Vertices should be between 0 and " << V-1 << endl;
            i--; // Retry this edge
            continue;
        }
        
        g.addEdge(u, v, w);
    }
    
    // Print the input graph
    cout << "\nGraph representation:" << endl;
    cout << "Number of vertices: " << V << endl;
    cout << "Number of edges: " << E << endl;
    
    // Run Prim's algorithm
    g.primMST();
    
    return 0;
}