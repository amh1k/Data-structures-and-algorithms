#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    

public:
vector<int> size;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
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

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int>delRow = {-1, 0, 1, 0};
        vector<int>delCol = {0, 1, 0, -1};
        int maxi = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++ ){

                if (grid[row][col] == 0)continue;
                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if (newRow >= 0 && newRow <n && newCol >= 0 && newCol < n &&  grid[newRow][newCol] == 1) {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;
                        ds.unionBySize(node, adjNode);

                    }
                }
            }
        }
        for (int row = 0; row <  n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                unordered_set<int>st;
                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                         int node = row * n + col;
                        int adjNode = newRow * n + newCol;
                        st.insert(ds.findParent(adjNode));
                    }
                }
                int totalSize = 0;
                for (auto it: st) {
                    totalSize += ds.size[it];

                }
                maxi = max(maxi, totalSize + 1);
            }
        }
        for (int cellNo = 0; cellNo < n; cellNo++) {
            maxi = max(maxi, ds.size[ds.findParent(cellNo)]);
        }
        return maxi;
        
    }
};