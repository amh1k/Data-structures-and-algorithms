#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionBySize(i+ 1, j+ 1);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i + 1) == i + 1) {
                cnt ++;
            }
        }
        return cnt;
        
    }
};