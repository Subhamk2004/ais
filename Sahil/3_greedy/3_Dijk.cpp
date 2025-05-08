#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(int graph[V][V]) {
    int parent[V]; // Stores MST
    int key[V];    // Used to pick minimum weight edge
    bool mstSet[V]; // True if vertex is included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;     // Start from first vertex
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update keys and parent index
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
