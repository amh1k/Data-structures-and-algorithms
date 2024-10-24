//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>>adj[n + 1];
      for (int i = 0; i < m; i++) {
          adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      }
        // Code herep
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({1, 0});
        vector<int>distance(n + 1, 1e9);
        distance[1] = 0;
        vector<int>parent(n + 1);
        for (int i = 1; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    while (!pq.empty()) {
        int node = pq.top().first;
        int dist = pq.top().second;
        for (auto it: adj[node]) {
            int nbr = it.first;
            int weight = it.second;
            pq.pop();
            if (dist + weight < distance[nbr]) {
                distance[nbr] = dist + weight;
                pq.push({nbr, distabce[nbr]});
                parent[it] = node;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends