#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
class Graph {
public:
    int V, E;
    vector<Edge> edges;
    
    // Constructor
    Graph(int v, int e) {
        V = v;
        E = e;
        edges.resize(e);
    }
    
    // Function to add an edge
    void addEdge(int i, int src, int dest, int weight) {
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }
};

// Structure for subset for union-find
class Subset {
public:
    int parent;
    int rank;
};

// Function to find set of an element i (uses path compression technique)
int find(vector<Subset>& subsets, int i) {
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

// Function that does union of two sets x and y (uses union by rank)
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        // If ranks are same, make one as root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function to be used by sort for edges
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to construct and print MST using Kruskal's algorithm
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result(V - 1);  // This will store the resultant MST
    
    // Step 1: Sort all edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);
    
    // Create V subsets with single elements
    vector<Subset> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Number of edges to be taken is equal to V-1
    int e = 0;  // Index used for result[]
    int i = 0;  // Index used for sorted edges
    
    // Process all sorted edges one by one
    while (e < V - 1 && i < graph.E) {
        // Step 2: Pick the smallest edge
        Edge next_edge = graph.edges[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        // If including this edge doesn't cause cycle, include it in result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
    
    // Print the constructed MST
    cout << "\nEdges of Minimum Spanning Tree:\n";
    int minimumCost = 0;
    cout << "Edge \tWeight\n";
    for (i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " \t" << result[i].weight << endl;
        minimumCost += result[i].weight;
    }
    cout << "Total cost of MST: " << minimumCost << endl;
}

int main() {
    int V, E;
    
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    Graph graph(V, E);
    
    cout << "\nFor each edge, enter source, destination, and weight:\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Edge " << i+1 << " (src dest weight): ";
        cin >> src >> dest >> weight;
        graph.addEdge(i, src, dest, weight);
    }
    
    // Perform Kruskal's algorithm
    KruskalMST(graph);
    
    return 0;
}