//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*') {
                st.push(ch);
            } else {
                if (ch == ')') {
                    bool isRedundant = true;
                    while (st.top() != '(') {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/') {
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    st.pop(); // pop the '('
                    if (isRedundant) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        int res = obj.checkRedundancy(s);
        cout << res << endl;
    }
}

// } Driver Code Ends
