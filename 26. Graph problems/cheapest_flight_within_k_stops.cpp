#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // int n = flights.size();
        int m = flights[0].size();
       vector<pair<int, int>> adj[n];
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});//(steps, node, weight)
        
        vector<int>distance(n, INT_MAX);
        distance[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.second.first;
            int cost = it.second.second;
            
            int step = it.first;
            if (step > k) continue;
            for (auto it: adj[node]) {
                int edgeWt = it.second;
                int nbr = it.first;
                if (cost + edgeWt < distance[nbr] && step + 1 <= k + 1) {
                    distance[nbr] = cost + edgeWt;
                    q.push({step + 1, {nbr, cost + edgeWt}});

                } 

            }         
            }
           return distance[dst] == INT_MAX ? -1 : distance[dst];
        
    }
};