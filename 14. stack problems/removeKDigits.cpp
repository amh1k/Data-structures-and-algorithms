#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//The idea is to maintain a linearily increasing order stack like in next smaller element



class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int count = k;
        string ans;
        if (num.size() == k) {
            return "0";
        }
        for (int i = 0; i < num.size(); i++) {
            while (count != 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                count --;
            }
            st.push(num[i]);

        }
        while (count > 0 && !st.empty()) {
            st.pop();
            count --;
        }

        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if (ans == "0") {
            return ans;
        }
        while (ans[0] ==  '0' && ans.size() > 1) {
            ans.erase(0, 1);
        }
        return ans;
         
    }
};