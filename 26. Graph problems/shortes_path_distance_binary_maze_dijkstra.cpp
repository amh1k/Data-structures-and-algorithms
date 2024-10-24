#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
       
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if (n == 1 || m == 1) return 1;
        queue<pair<int, pair<int,int>>>q;
        q.push({1, {0, 0}});
        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = 1;
       vector<int> delRow = {-1, 0, 1, 0, -1, -1, 1, 1};
        vector<int> delCol = {0, 1, 0, -1, -1, 1, -1, 1};
        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0 && dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    if (newRow == n - 1 && newCol == m - 1) return dist + 1;
                    q.push({distance[newRow][newCol], {newRow, newCol}});

                }
            }
            
        }
        return -1;
        
    }
};