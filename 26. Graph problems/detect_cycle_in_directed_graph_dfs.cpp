//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(vector<int>adj[],int node, vector<int>&visited, vector<int>&visitedPath) {
      visited[node] = 1;
      visitedPath[node] = 1;
      for (auto it: adj[node]) {
          if (visited[it] == 0) {
              if (dfs(adj, it, visited, visitedPath)) return true;
          }
          else if (visitedPath[it] == 1) {
              return true;
          }
      }
      visitedPath[node] = 0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int>visitedPath(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, visitedPath)) {
                    return true;
                }
            }
        }
        return false;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends