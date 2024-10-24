#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  void solve(string s, vector<string>&temp, vector<vector<string>>&ans, int index, int n) {
    if (index == n) {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < n; i++) {
        if (isValid(s, index, i) ) {
            temp.push_back(s.substr(index, i - index + 1));
            solve(s, temp, ans, i + 1, n);
            temp.pop_back();


        }
    }
  }
  bool isValid(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--] ) return false;
    }
    return true;
  }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s, temp, ans, 0, s.size());
        return ans;
        
    }
};