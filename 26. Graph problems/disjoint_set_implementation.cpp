#include <iostream>
#include <vector>
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
class DisjointSetByRank {
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSetByRank(int n) {
        rank.resize(n + 1, 0);  // Initialize ranks to 0
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

    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV) return;  // Already in the same set

        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

int main() {
    DisjointSet ds(5);
    
    ds.unionBySize(1, 2);
    ds.unionBySize(3, 4);
    ds.unionBySize(2, 3);
    
    cout << "Parent of 4: " << ds.findParent(4) << endl;
    cout << "Parent of 1: " << ds.findParent(1) << endl;

    return 0;
}
