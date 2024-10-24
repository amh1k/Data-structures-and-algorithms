#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path compression
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int uParentU = findParent(u);
        int uParentV = findParent(v);

        if (uParentU == uParentV) return;

        // Union by size
        if (size[uParentU] > size[uParentV]) {
            size[uParentU] += size[uParentV];
            parent[uParentV] = uParentU;
        } else {
            size[uParentV] += size[uParentU];
            parent[uParentU] = uParentV;
        }
    }
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>>edges;
        for (int i = 0; i < V; i++) {
            for (auto it: adj[i]) {
            // int node = it[0];
            int nbr = it[0];
            int wt = it[1];
            edges.push_back({wt, {i, nbr}});
            
        }
        
            
            
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstWt = 0;
        for (auto it: edges) {
            int wt = it.first;
            int node = it.second.first;
            int nbr = it.second.second;
            if (ds.findParent(node) != ds.findParent(nbr)) {
                ds.unionBySize(node, nbr);
                mstWt += wt;
                ds.unionBySize(node, nbr);
            }
        }
        return mstWt;
        
        
        // code here
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
