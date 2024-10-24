#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>adj[], int node, vector<int>&visited, vector<int>&visitedPath, vector<int>&check) {
        visited[node] = 1;
        visitedPath[node] = 1;
        check[node] = 0;
        for (auto it: adj[node]) {
            if (!visited[it]) {
                if (dfs(adj, it, visited, visitedPath, check) == true) {
                    return true;
                }
            }
            else if (visitedPath[it] == 1) {
                return true;
            }
        }
        check[node] = 1;
        visitedPath[node] = 0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>adj[v];
        for (int i = 0; i < v; i++) {
            for (auto j: graph[i]) {
                adj[i].push_back(j);
            }
        }
        vector<int> visited(v, 0);
        vector<int>visitedPath(v, 0);
        vector<int>check(v, 0);
        vector<int>ans;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, visitedPath, check);
            }
        }
        for (int i = 0; i < v; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};