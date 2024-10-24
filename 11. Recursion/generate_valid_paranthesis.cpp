#include<iostream>
#include<bits/stdc++.h>

class Solution {
public:
 
   void solve(int n, string &temp, vector<string>& ans, int index, int open, int close) {
    if (index == n*2 && open == close) {
        ans.push_back(temp);
        return;
    }
    if (open < n) {
        temp.push_back('(');
        solve(n, temp, ans, index + 1, open + 1, close);
         temp.pop_back();

    }
     if (close < open) {
        temp.push_back(')');
        solve(n, temp, ans, index + 1, open, close + 1);
         temp.pop_back();

    }
   
    
   
    // temp.push_back(')');
    // solve(n, temp,ans, index + 1);
   }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(n, temp, ans, 0, 0, 0);
        return ans;
        
    }
};