#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
       
        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
         int n = stones.size(); 
        DisjointSet ds(maxRow + maxCol +2);
        unordered_map<int,int>mp;
        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1]+ maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mp[nodeRow] = 1;
            mp[nodeCol] = 1;


        }
        int cnt = 0;
        for (auto it: mp) {
            if (ds.findParent(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;

        
    }
};