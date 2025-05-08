#include<bits/stdc++.h>
using namespace std;
// Function to perform DFS traversal

void dfs(vector<vector<int> >& adj, int node, vector<int> & visited){
    visited[node]=1;
        cout<<node<<" ";

        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,it,visited);
            }
        }
}

int main(){
cout<< "Enter The Number of Edges and Vertices"<<endl;
int vertices, edges;
cin >> vertices >> edges;
vector<vector<int>> adj(vertices);
// vector<vector<int>> adj ={
//     {2,3},
//     {3},
//     {0},
//     {0,1,4},
//     {3}
// };
cout<< "ENTER THE EDGES"<<endl;
    for(int i=0;i<edges;i++){ 
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(5,0);
    dfs(adj,0,visited);
}


