Basic Concepts
1. What is a Minimum Spanning Tree (MST)?

Solution: A Minimum Spanning Tree (MST) is a subset of the edges of a connected, undirected, weighted graph that connects all vertices together with the minimum possible total edge weight, without creating any cycles. It's a spanning tree whose sum of edge weights is as small as possible.


2. Explain the difference between a spanning tree and a minimum spanning tree.

Solution: A spanning tree is any tree that includes all vertices of the original graph without cycles. A minimum spanning tree is specifically the spanning tree that has the smallest total edge weight among all possible spanning trees. All MSTs are spanning trees, but not all spanning trees are MSTs.


3. Can a graph have multiple minimum spanning trees? If yes, under what conditions?

Solution: Yes, a graph can have multiple MSTs if it contains edges with equal weights. When there are multiple edges with the same weight, different selections of these edges can result in different spanning trees with identical total weights.


4. What's the maximum number of edges in a MST for a graph with n vertices?

Solution: A MST for a graph with n vertices will always have exactly (n-1) edges. This is a property of all trees - they must have exactly one less edge than the number of vertices.


5. Why is Kruskal's algorithm classified as a greedy algorithm?

Solution: Kruskal's algorithm is greedy because it makes the locally optimal choice at each step by selecting the edge with the lowest weight that doesn't create a cycle, without considering the global structure. It builds the solution incrementally, always choosing the best immediate option available.


6. What is the time complexity of Kruskal's algorithm? Explain why.

Solution: The time complexity of Kruskal's algorithm is O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices. This is because:

Sorting the edges takes O(E log E) time
Processing each edge using Union-Find takes O(E × α(V)) time, where α is the inverse Ackermann function, which grows very slowly and is effectively a constant for all practical purposes
Since log V and log E are related (E can be at most V²), the overall complexity is O(E log E) or O(E log V)


7. What are the applications of minimum spanning trees in real-world scenarios?

Solution:

Network design (telecommunications, electrical grids, water supply networks)
Approximation algorithms for NP-hard problems like the Traveling Salesman Problem
Cluster analysis in data mining
Image segmentation in computer vision
Circuit design in electronics
Transportation networks and route planning
Network routing protocols



Algorithm Understanding

8. Describe the steps of Kruskal's algorithm in your own words.

Solution:

Sort all edges in the graph in non-decreasing order of their weight
Initialize an empty set to hold the MST edges
For each edge in the sorted list, check if adding it creates a cycle with the edges already in the MST set
If no cycle is formed, add the edge to the MST set
Continue until the MST has (n-1) edges, where n is the number of vertices
The resulting set of edges forms the minimum spanning tree


9. How does Kruskal's algorithm ensure that no cycles are formed during edge selection?

Solution: Kruskal's algorithm uses a disjoint-set data structure (Union-Find) to detect cycles. Before adding an edge that connects vertices u and v, it checks if u and v are already in the same connected component (by checking if they have the same representative/parent). If they are, adding this edge would create a cycle, so it's skipped. If they're in different components, the edge is added and the two components are merged using the Union operation.


10. What's the difference between Kruskal's and Prim's algorithms for finding MST?

Solution:
Kruskal's algorithm starts with an empty graph and adds edges in order of increasing weight, skipping those that would create cycles. It uses Union-Find data structure and processes edges globally.
Prim's algorithm starts with a single vertex and grows the tree one vertex at a time, always adding the lowest-weight edge that connects the current tree to a new vertex. It uses a priority queue and grows the MST from a single source.
Kruskal's works well for sparse graphs, while Prim's can be more efficient for dense graphs.


11. When would you prefer Kruskal's algorithm over Prim's algorithm?
Solution: Kruskal's algorithm is preferred over Prim's algorithm in the following scenarios:

When the graph is sparse (has few edges compared to the number of vertices)
When edges are already sorted or can be sorted efficiently
When implementing the algorithm in a distributed system
When the graph is not connected (Kruskal's can find the minimum spanning forest)
When the Union-Find data structure is already implemented and optimized


12. What happens if the graph has negative edge weights? Would Kruskal's algorithm still work?

Solution: Yes, Kruskal's algorithm works correctly with negative edge weights. Unlike shortest path algorithms like Dijkstra's, MST algorithms don't accumulate weights along paths, so negative edges don't create any special problems. Kruskal's algorithm will still select edges in order of increasing weight (including negative weights) and produce the correct MST.


13. What happens if the graph is not connected? What would Kruskal's algorithm produce?

Solution: If the graph is not connected, Kruskal's algorithm will produce a Minimum Spanning Forest (MSF) instead of a single MST. This forest consists of a minimum spanning tree for each connected component of the graph. The algorithm works exactly the same way, but stops when it has selected (n-k) edges, where n is the number of vertices and k is the number of connected components.


14. How does Kruskal's algorithm handle parallel edges between the same vertices?

Solution: When there are multiple (parallel) edges between the same pair of vertices, Kruskal's algorithm will consider all of them in its sorted list of edges. However, once an edge between two vertices is added to the MST, any subsequent parallel edges between the same vertices will create a cycle and thus be discarded. Therefore, at most one edge from each set of parallel edges will be included in the MST, specifically the one with the minimum weight.