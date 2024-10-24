//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<int>ans;
         vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        DisjointSet ds(n * m);
        for (auto it: operators) {
            int row = it[0];
            int col = it[1];
            if (visited[row][col] == 1)continue;
            cnt++;
            visited[row][col] = 1;
            vector<int>delRow = {-1, 0, 1, 0};
            vector<int>delCol = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];
               
                if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m) {
                    if (visited[adjRow][adjCol] == 1) {
                         int node = row * m + col;
                int adjNode = adjRow * m + adjCol;
                        if (ds.findParent(node) != ds.findParent(adjNode)) {
                            cnt --;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends