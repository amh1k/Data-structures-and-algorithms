#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>dijkstra(vector<pair<int, int>>adj[], int src ,int n) {
        vector<int>distance(n, INT_MAX);
        distance[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dist = it.first;
            for (auto it: adj[node]) {
                int nbr = it.first;
                int wt = it.second;
                if (dist + wt < distance[nbr]) {
                    distance[nbr] = dist + wt;
                    pq.push({dist + wt, nbr});
                }
            }
        }
        return distance;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for (auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});


        }
        vector<vector<int>>distance(n, vector(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            distance[i] = dijkstra(adj, i, n);
        }
        int cntMin = INT_MAX;
        long long cnt = 0;
        int cityNumber = -1;
        for (int i = 0; i < n; i++) {
             cnt = 0;
            for (int j = 0; j < n; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    cnt ++;
                }
            }
            if (cnt <= cntMin) {
                cntMin = cnt;
                cityNumber = i;
            }
       
        }
        return cityNumber;

        
    }
};