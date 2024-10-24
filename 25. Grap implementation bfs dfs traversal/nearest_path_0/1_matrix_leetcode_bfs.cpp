#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0;  i< n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }

            }
        }
        int delRows[4] = {-1, 0, 1, 0};
        int delCols[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[row][col] = steps;
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRows[i];
                int nCol = col + delCols[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 0) {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }



        }
        return ans;
        
        
    }
};