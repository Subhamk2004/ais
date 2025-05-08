#include <bits/stdc++.h>
using namespace std;

// O(E log E + E * α(V))

// Disjoint Set Union (DSU) using Union by Size + Path Compression
class DisjointSet {
    vector<int> parent, size;
    
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int findUPar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; // Already connected

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Kruskal's Algorithm
void kruskal(int V, vector< pair<int,pair<int,int>> > & edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    for (auto it : edges) {
        int wt = it.first;
        int u= it.second.first;
        int v= it.second.second;
        if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWeight += wt;
            mstEdges.push_back({u, v});
            ds.unionBySize(u, v);
        }
    }

    // Output
    cout << "Minimum Spanning Tree Edges:\n";
    for (auto [u, v] : mstEdges) {
        cout << u << " - " << v << endl;
    }
    cout << "Total Weight of MST: " << mstWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int,pair<int,int>>> edges;
  
    cout << "Enter each edge as: node1 node2 weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
    }

    kruskal(V, edges);

    return 0;
}





//     Disjointset ds(3);
//     ds.unionbysize(1,2);
//   if(ds.findupar(2)==ds.findupar(3)){
//     cout<<"Parents are same"<<endl;
//   }else {
//     cout<<"Parents are not same"<<endl;
//   }
//    ds.unionbysize(2,3);
//    if(ds.findupar(2)==ds.findupar(3)){
//     cout<<"Parents are same"<<endl;
//   }else {
//     cout<<"Parents are not same"<<endl;
//   }
