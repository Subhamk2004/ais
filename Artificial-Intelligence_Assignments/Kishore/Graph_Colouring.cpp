#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to assign color to vertex
bool isSafe(int node, vector<int>& color, vector<vector<int>>& graph, int n, int col) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve graph coloring
bool solve(int node, vector<vector<int>>& graph, int m, int n, vector<int>& color) {
    if (node == n) return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, graph, n, col)) {
            color[node] = col;
            if (solve(node + 1, graph, m, n, color))
                return true;
            color[node] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to solve m-coloring problem
bool graphColoring(vector<vector<int>>& graph, int m, int n) {
     vector<int> color = {0}; // Initially all vertices are uncolored
    return solve(0, graph, m, n, color);
}

int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors

    // Example graph (Adjacency Matrix)
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (graphColoring(graph, m, n))
        cout << "Coloring possible with " << m << " colors.\n";
    else
        cout << "Coloring NOT possible with " << m << " colors.\n";

    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// // Check if it's safe to assign color to vertex
// bool isSafe(int node, int color[], vector<vector<int>>& graph, int n, int col) {
//     for (int k = 0; k < n; k++) {
//         if (graph[node][k] == 1 && color[k] == col) {
//             return false;
//         }
//     }
//     return true;
// }

// // Backtracking function to solve graph coloring
// bool solve(int node, vector<vector<int>>& graph, int m, int n, int color[]) {
//     if (node == n) return true;

//     for (int col = 1; col <= m; col++) {
//         if (isSafe(node, color, graph, n, col)) {
//             color[node] = col;
//             if (solve(node + 1, graph, m, n, color))
//                 return true;
//             color[node] = 0; // Backtrack
//         }
//     }
//     return false;
// }

// // Main function to solve m-coloring problem
// bool graphColoring(vector<vector<int>>& graph, int m, int n) {
//     int color[n] = {0}; // Initially all vertices are uncolored
//     return solve(0, graph, m, n, color);
// }

// int main() {
//     int n = 4; // Number of vertices
//     int m = 3; // Number of colors

//     // Example graph (Adjacency Matrix)
//     vector<vector<int>> graph = {
//         {0, 1, 1, 1},
//         {1, 0, 1, 0},
//         {1, 1, 0, 1},
//         {1, 0, 1, 0}
//     };

//     if (graphColoring(graph, m, n))
//         cout << "Coloring possible with " << m << " colors.\n";
//     else
//         cout << "Coloring NOT possible with " << m << " colors.\n";

//     return 0;
// }
