#include <bits/stdc++.h>
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a vertex in the priority queue
struct Vertex {
    int id;
    int distance;
    
    // Operator overloading for priority queue comparison
    bool operator>(const Vertex& other) const {
        return distance > other.distance;
    }
};

class Graph {
private:
    int V; // Number of vertices
    vector<vector<Edge>> adjList; // Adjacency list
    
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }
    
    // Function to add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        Edge edge;
        edge.destination = destination;
        edge.weight = weight;
        adjList[source].push_back(edge);
        
        // For undirected graph, add edge in the other direction too
        edge.destination = source;
        adjList[destination].push_back(edge);
    }
    
    // Dijkstra's algorithm to find shortest paths from a source vertex
    vector<int> dijkstra(int source) {
        // Create a priority queue for vertices
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        
        // Create vector for distances and initialize all distances as infinite
        vector<int> dist(V, numeric_limits<int>::max());
        
        // Create vector to track if a vertex is included in SPT
        vector<bool> sptSet(V, false);
        
        // Create vector for parent to reconstruct path
        vector<int> parent(V, -1);
        
        // Distance of source vertex from itself is always 0
        dist[source] = 0;
        
        // Insert source vertex into the priority queue
        Vertex src = {source, 0};
        pq.push(src);
        
        // Process vertices until priority queue becomes empty
        while (!pq.empty()) {
            // Extract the vertex with minimum distance value
            Vertex u = pq.top();
            pq.pop();
            
            int u_id = u.id;
            
            // If vertex is already in SPT, skip
            if (sptSet[u_id])
                continue;
                
            // Include vertex in SPT
            sptSet[u_id] = true;
            
            // Update distances of all adjacent vertices
            for (const Edge& edge : adjList[u_id]) {
                int v = edge.destination;
                int weight = edge.weight;
                
                // If vertex v is not in SPT and distance to v through u is less than its current distance
                if (!sptSet[v] && dist[u_id] != numeric_limits<int>::max() && 
                    dist[u_id] + weight < dist[v]) {
                    // Update distance of v
                    dist[v] = dist[u_id] + weight;
                    parent[v] = u_id;
                    
                    // Insert v into the priority queue
                    Vertex vertex = {v, dist[v]};
                    pq.push(vertex);
                }
            }
        }
        
        return dist;
    }
    
    // Function to print the path from source to a specific vertex
    void printPath(vector<int>& parent, int j) {
        // Base Case: If j is source or path doesn't exist
        if (parent[j] == -1)
            return;
            
        printPath(parent, parent[j]);
        cout << " -> " << j;
    }
    
    // Function to print all shortest paths from a source vertex
    void printSolution(vector<int>& dist, vector<int>& parent, int source) {
        cout << "Vertex\tDistance\tPath" << endl;
        
        for (int i = 0; i < V; i++) {
            if (i != source) {
                cout << i << "\t" << dist[i] << "\t\t" << source;
                printPath(parent, i);
                cout << endl;
            }
        }
    }
    
    // Full Dijkstra with path reconstruction
    void shortestPaths(int source) {
        // Create a priority queue for vertices
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        
        // Create vector for distances and initialize all distances as infinite
        vector<int> dist(V, numeric_limits<int>::max());
        
        // Create vector to track if a vertex is included in SPT
        vector<bool> sptSet(V, false);
        
        // Create vector for parent to reconstruct path
        vector<int> parent(V, -1);
        
        // Distance of source vertex from itself is always 0
        dist[source] = 0;
        
        // Insert source vertex into the priority queue
        Vertex src = {source, 0};
        pq.push(src);
        
        // Process vertices until priority queue becomes empty
        while (!pq.empty()) {
            // Extract the vertex with minimum distance value
            Vertex u = pq.top();
            pq.pop();
            
            int u_id = u.id;
            
            // If vertex is already in SPT, skip
            if (sptSet[u_id])
                continue;
                
            // Include vertex in SPT
            sptSet[u_id] = true;
            
            // Update distances of all adjacent vertices
            for (const Edge& edge : adjList[u_id]) {
                int v = edge.destination;
                int weight = edge.weight;
                
                // If vertex v is not in SPT and distance to v through u is less than its current distance
                if (!sptSet[v] && dist[u_id] != numeric_limits<int>::max() && 
                    dist[u_id] + weight < dist[v]) {
                    // Update distance of v
                    dist[v] = dist[u_id] + weight;
                    parent[v] = u_id;
                    
                    // Insert v into the priority queue
                    Vertex vertex = {v, dist[v]};
                    pq.push(vertex);
                }
            }
        }
        
        // Print the solution
        printSolution(dist, parent, source);
    }
    
    // Function to print the graph
    void printGraph() {
        cout << "Graph Structure:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " is connected to: ";
            for (const Edge& edge : adjList[i]) {
                cout << "(" << edge.destination << ", weight: " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a sample graph
    cout << "Enter number of vertices: ";
    int V;
    cin >> V;
    
    Graph g(V);
    
    cout << "Enter number of edges: ";
    int E;
    cin >> E;
    
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }
    
    // Print the graph structure
    g.printGraph();
    
    // Get source vertex for Dijkstra's algorithm
    cout << "Enter source vertex for Dijkstra's algorithm: ";
    int source;
    cin >> source;

    // Apply Dijkstra's algorithm and print the shortest paths
    cout << "\nShortest paths from vertex " << source << ":" << endl;
    g.shortestPaths(source);
    
    return 0;
}