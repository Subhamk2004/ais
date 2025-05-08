#include<bits/stdc++.h>
using namespace std;
// Function to perform BFS traversal
// Complexity: O(V+E) where V is the number of vertices and E is the number of edges
void bfs(vector<vector<int>>& adj, int node, vector<int>& vis){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(auto it:adj[front]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

int main(){
    // int u,v;
    // cin>>u>>v;
    // vector<vector<int>> adj(u);
    // for(int i=0;i<v;i++){
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // vector<int> vis(u,0);
    // bfs(adj,0,vis);

    int vertices =6;
    vector<vector<int>> adj(vertices);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};
    vector<int> vis(vertices, 0);
    cout<<"BFS Traversal: ";
    bfs(adj, 0, vis);
    cout<<endl;

}

void 