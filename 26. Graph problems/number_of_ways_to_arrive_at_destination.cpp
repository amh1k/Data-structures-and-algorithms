#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>>adj[n];
        int r = roads.size();
        for (auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long>distance(n, LLONG_MAX);
        vector<long long>ways(n, 0);
        pq.push({0, 0});
        distance[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long node = it.second;
            long long dist = it.first;
            for (auto it: adj[node]) {
                long long nbr = it.first;
                long long wt = it.second;
                if (dist + wt < distance[nbr]) {
                    distance[nbr] = dist + wt;
                    pq.push({dist  + wt, nbr});
                    ways[nbr] = (ways[node]) % mod;
                }
                else if (dist + wt == distance[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;

        
    }
};