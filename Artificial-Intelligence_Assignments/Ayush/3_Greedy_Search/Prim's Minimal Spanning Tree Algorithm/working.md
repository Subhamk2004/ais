argus@pop-os:~/Documents/AI/3_Greedy_Search$ g++ Prims.cpp
argus@pop-os:~/Documents/AI/3_Greedy_Search$ ./a.out
Enter number of vertices: 5
Enter number of edges: 7
Enter the edges in format <source> <destination> <weight>:
(Note: Vertices are numbered from 0 to 4)
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Graph representation:
Number of vertices: 5
Number of edges: 7

Edges in the Minimum Spanning Tree:
0 - 1 (weight: 2)
1 - 2 (weight: 3)
0 - 3 (weight: 6)
1 - 4 (weight: 5)
Total weight of MST: 16







How Prim's Algorithm Works
Prim's algorithm is a greedy algorithm that:

Starts with an arbitrary vertex
Grows the MST one vertex at a time
In each step, adds the lowest weight edge that connects a vertex in the MST to a vertex outside the MST

Implementation Highlights

Used adjacency list representation for the graph
Implemented a priority queue to efficiently select the next minimum-weight edge
Tracked which vertices are already in the MST
Maintained a parent array to reconstruct the MST edges

Example Cases
The code includes two example cases:
Example 1: 5-vertex graph

7 edges with varying weights
Shows edges selected for the MST and their weights
Calculates total MST weight

Example 2: 6-vertex graph

9 edges with varying weights
More complex example to verify the algorithm works correctly

Expected Output
When you run the program, it will:

Print the input graph representation
Run Prim's algorithm
Display the edges selected for the MST
Show the total weight of the MST

The output will demonstrate how the algorithm selects edges to form the minimum spanning tree while avoiding cycles and minimizing the total weight.


