// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution {
public:
    bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> &visited) {
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>> &m, int n, int x, int y, string path, vector<string> &ans, vector<vector<int>> &visited) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        if (isSafe(m, n, x + 1, y, visited)) {
            path.push_back('D');
            solve(m, n, x + 1, y, path, ans, visited);
            path.pop_back();
        }
        // Left
        if (isSafe(m, n, x, y - 1, visited)) {
            path.push_back('L');
            solve(m, n, x, y - 1, path, ans, visited);
            path.pop_back();
        }
        // Right
        if (isSafe(m, n, x, y + 1, visited)) {
            path.push_back('R');
            solve(m, n, x, y + 1, path, ans, visited);
            path.pop_back();
        }
        // Up
        if (isSafe(m, n, x - 1, y, visited)) {
            path.push_back('U');
            solve(m, n, x - 1, y, path, ans, visited);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if (m[0][0] == 0) {
            return ans;
        }

        int x = 0, y = 0;
        string path;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(m, n, x, y, path, ans, visited);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.empty()) {
            cout << -1;
        } else {
            for (const string &path : result) {
                cout << path << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
