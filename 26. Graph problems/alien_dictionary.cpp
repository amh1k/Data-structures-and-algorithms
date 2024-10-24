//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for (int i = 0; i < N - 1; i++) {
            string string1 = dict[i];
            string string2 = dict[i + 1];
            int len = min(string1.size(), string2.size());
            for (int i =0; i < len; i++) {
                if (string1[i] != string2[i]) {
                    adj[string1[i] - 'a'].push_back(string2[i] - 'a');
                    break;
                }
            }
            
        }
        //Simple toposort
        queue<int>q;
        vector<int>inedges(K, 0);
        for (int i = 0; i < K; i++) {
            for (auto it: adj[i]) {
                inedges[it]++;
            }
        }
        for (int i = 0; i < K; i++) {
            if (inedges[i] == 0) {
                q.push(i);
            }
        }
        vector<int>topo;
        
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it: adj[node]) {
                inedges[it]--;
                if (inedges[it] == 0) {
                    q.push(it);
                    
                }
                
            }
        }
        string ans = "";
        for (auto it: topo) {
            ans = ans + char(it + 'a');
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends