argus@pop-os:~/Documents/AI/3_Greedy_Search$ g++ Kruskals.cpp
argus@pop-os:~/Documents/AI/3_Greedy_Search$ ./a.out
Enter number of vertices: 4
Enter number of edges: 5

For each edge, enter source, destination, and weight:
Edge 1 (src dest weight): 0 1 10
Edge 2 (src dest weight): 0 2 6
Edge 3 (src dest weight): 0 3 5
Edge 4 (src dest weight): 1 3 15
Edge 5 (src dest weight): 2 3 4

Edges of Minimum Spanning Tree:
Edge    Weight
2 - 3   4
0 - 3   5
0 - 1   10
Total cost of MST: 19



How the Algorithm Works
Kruskal's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph. It works as follows:

Sort all edges in non-decreasing order of their weight.
Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far using Union-Find data structure.

If cycle is not formed, include this edge.
Else, discard it.


Repeat step 2 until there are (V-1) edges in the spanning tree, where V is the number of vertices.

Code Explanation

Data Structures:

Edge struct: Represents an edge with source, destination, and weight
Graph class: Contains a list of edges and number of vertices
Subset class: Used for the Union-Find algorithm to detect cycles


Union-Find Operations:

find(): Finds the representative (parent) of a set using path compression
Union(): Merges two sets based on rank to maintain a balanced tree


Algorithm Flow:

Sort all edges by weight (using compareEdges function)
Initialize each vertex as a separate subset
For each edge in sorted order:

Check if including the edge creates a cycle using Union-Find
If no cycle is formed, include the edge in the MST


Print the final MST and its total cost


User Input:

The program takes the number of vertices and edges
For each edge, it takes source, destination, and weight



This implementation efficiently handles the graph using adjacency list representation and employs Union-Find with path compression and union by rank for optimal performance, resulting in O(E log E) time complexity where E is the number of edges.