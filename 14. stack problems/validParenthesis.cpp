#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(ch);
            }
            else {
                if (!stk.empty()) { 
                    if ((ch == ')' && stk.top() == '(') || (ch == '}' && stk.top() == '{') || (ch == ']' && stk.top() == '[')) {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
                }
            
        }
        if (stk.empty()) {
            return true;
        }
        else {
            return false;
        }
        
    }
};