#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>adj[v];
        for (int i = 0; i < v; i++) {
            for (auto j: graph[i]) {
                adj[i].push_back(j);
            }
        }
        vector<int>reverseAdj[v];
        vector<int>indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it: adj[i]) {
                reverseAdj[it].push_back(i);
                indegree[i] ++;
            }
        }
        queue<int>q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it: reverseAdj[node]) {
                indegree[it] --;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;

        
        
    }
};