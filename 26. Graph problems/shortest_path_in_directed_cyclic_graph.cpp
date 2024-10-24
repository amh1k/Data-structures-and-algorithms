//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int, int>>adj[N];
         for (int i = 0; i < M; i++ ) {
             int node = edges[i][0];
             int edge = edges[i][1];
             int weight = edges[i][2];
             adj[node].push_back({edge, weight});
             
             
             
         }
         vector<int>distance(N, INT_MAX);
         distance[0] = 0;
         queue<int>q;
         q.push(0);
         while (!q.empty()) {
             int node = q.front();
             q.pop();
             
             for (auto it: adj[node]) {
                 int dist = it.second;
                 if (distance[node] + dist < distance[it.first]) {
                     distance[it.first] = distance[node] + dist;
                     q.push(it.first);
                 }
             }
         }
         for (int i = 0; i < distance.size(); i++) {
             if (distance[i] == INT_MAX) distance[i] = -1;
         }
         return distance;
         
         
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends