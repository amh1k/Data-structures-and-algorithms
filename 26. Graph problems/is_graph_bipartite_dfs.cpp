#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool dfs( int node, vector<int>adj[], vector<int>&color, int col) {
    color[node] = col;
    for (auto it: adj[node]) {
        if (color[it] == -1) {
            if (dfs(it, adj, color, !col) == false) {
                return false;

            }  
        }
         else if (color[it] == col) {
            return false;
        }
            


        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);

        vector<int>adj[v];
         for (int i = 0; i < v; i++) {
            for (int j : graph[i]) {
                adj[i].push_back(j);
            }
        }
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (dfs(i, adj, color, 0) == false) return false;
            }
        }
        return true;

        
    }
};