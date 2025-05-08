argus@pop-os:~/Documents/AI/3_Greedy_Search$ g++ Dijkastra.cpp
argus@pop-os:~/Documents/AI/3_Greedy_Search$ ./a.out
Enter number of vertices: 6
Enter number of edges: 9
Enter edges (source destination weight):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 5 1
4 3 2
4 5 5
5 2 6
Graph Structure:
Vertex 0 is connected to: (1, weight: 2) (2, weight: 4) 
Vertex 1 is connected to: (0, weight: 2) (2, weight: 1) (3, weight: 7) 
Vertex 2 is connected to: (0, weight: 4) (1, weight: 1) (4, weight: 3) (5, weight: 6) 
Vertex 3 is connected to: (1, weight: 7) (5, weight: 1) (4, weight: 2) 
Vertex 4 is connected to: (2, weight: 3) (3, weight: 2) (5, weight: 5) 
Vertex 5 is connected to: (3, weight: 1) (4, weight: 5) (2, weight: 6) 
Enter source vertex for Dijkstra's algorithm: 0

Shortest paths from vertex 0:
Vertex  Distance        Path
1       2               0 -> 1
2       3               0 -> 1 -> 2
3       8               0 -> 1 -> 2 -> 4 -> 3
4       6               0 -> 1 -> 2 -> 4
5       9               0 -> 1 -> 2 -> 5
argus@pop-os:~/Documents/AI/3_Greedy_Search$ 





or 



argus@pop-os:~/Documents/AI/3_Greedy_Search$ g++ Dijkastra.cpp
argus@pop-os:~/Documents/AI/3_Greedy_Search$ ./a.out
Enter number of vertices: 4  
Enter number of edges: 5
Enter edges (source destination weight):
0 1 5
0 2 3
1 2 3
1 3 6
2 3 4
Graph Structure:
Vertex 0 is connected to: (1, weight: 5) (2, weight: 3) 
Vertex 1 is connected to: (0, weight: 5) (2, weight: 3) (3, weight: 6) 
Vertex 2 is connected to: (0, weight: 3) (1, weight: 3) (3, weight: 4) 
Vertex 3 is connected to: (1, weight: 6) (2, weight: 4) 
Enter source vertex for Dijkstra's algorithm: 0

Shortest paths from vertex 0:
Vertex  Distance        Path
1       5               0 -> 1
2       3               0 -> 2
3       7               0 -> 2 -> 3





Implementation Details
The implementation includes:

A graph representation using adjacency lists
A priority queue to always select the vertex with the minimum distance
Path reconstruction to show the actual shortest path, not just the distance
Comprehensive output showing distances and paths

Key Greedy Aspects
Dijkstra's algorithm is greedy because:

It always selects the vertex with the minimum known distance
Once a vertex is processed, its shortest distance is finalized
It never reconsiders vertices that have been finalized

How to Use the Program

Enter the number of vertices in the graph
Enter the number of edges
For each edge, enter the source vertex, destination vertex, and weight
Specify a source vertex for computing shortest paths



Small Example Walkthrough
Graph Configuration

4 vertices (0, 1, 2, 3)
5 edges with various weights
Source vertex: 0

Step-by-Step Execution

Initialization:

Set distance of vertex 0 to 0
Set distances of all other vertices to infinity
Add vertex 0 to priority queue


First Iteration:

Extract vertex 0 from queue
Update distances of neighbors:

vertex 1: 5
vertex 2: 3


Add vertices 1 and 2 to priority queue


Second Iteration:

Extract vertex 2 (distance 3)
Update distances of neighbors:

vertex 3: min(∞, 3+4) = 7


Add vertex 3 to priority queue


Third Iteration:

Extract vertex 1 (distance 5)
No updates to distances (all paths through vertex 1 are longer)


Fourth Iteration:

Extract vertex 3 (distance 7)
All vertices processed



Final Result

Shortest path to vertex 1: 0 → 1 (distance 5)
Shortest path to vertex 2: 0 → 2 (distance 3)
Shortest path to vertex 3: 0 → 2 → 3 (distance 7)