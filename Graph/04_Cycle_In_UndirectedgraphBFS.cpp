//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool isCycleBFS(int node,unordered_map<int,bool>&visited,vector<int> adj[] ){
        
        
        unordered_map<int, int>parent;
        parent[node]=-1;
        visited[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int frontNode= q.front();
            q.pop();
            
            
            for(auto i:adj[frontNode]){
                if(visited[i]==true && i!=parent[frontNode]){
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                    parent[i]=frontNode;
                }
                    
                
            }
        }
        return false;
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        unordered_map<int,bool>visited;
        
        // sabhi components ke liye:
        for(int i=0; i<V; i++){
            if(!visited[i]){
                
                bool ans = isCycleBFS(i, visited, adj);
                
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends