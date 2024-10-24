#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        pq.push({0, {0, 0}});
        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = 0;
        vector<int>delRow = {-1, 0, 1, 0};
        vector<int>delCol = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            int dist = it.first;
            pq.pop();
            if (row == n -1 && col == m - 1) return dist;
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m )
                 { int maxEffort = max(dist, abs(heights[newRow][newCol] - heights[row][col]));
                   if (maxEffort < distance[newRow][newCol]) {
                        distance[newRow][newCol] = maxEffort;
                        pq.push({maxEffort, {newRow, newCol}});
                    }}
            }

        }
        
        return -1; // unreachable
    }
};