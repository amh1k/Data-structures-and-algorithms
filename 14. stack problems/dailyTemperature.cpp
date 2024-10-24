#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       
        stack<int>st;
        int n = temperatures.size();
         vector<int>ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= temperatures[i]) {
                st.pop();

            }
            if (st.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;

        
    }
};