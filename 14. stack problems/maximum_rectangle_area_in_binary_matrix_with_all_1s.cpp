
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);
        stack<int> st;

        //FOr prev smaller
        for (int i = 0; i < n; i++)  {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prevSmaller[i] = st.top() + 1;

            }
            else {
                prevSmaller[i] = 0;
            }
            st.push(i);
        }
        while (!st. empty()) {
            st.pop();
        }

        //For next smaller elements


        for (int i = n - 1; i >= 0; i--)  {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller[i] = st.top() - 1;

            }
            else {
                nextSmaller[i] = n - 1;
            }
            st.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * ((nextSmaller[i] - prevSmaller[i]) + 1));
        }
        return maxArea;
        


        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> M(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                M[i][j] = matrix[i][j] == '1' ? 1 : 0;
            }
        }

        int maxArea = largestRectangleArea(M[0]);
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (M[i][j] == 1) {
                    M[i][j] += M[i - 1][j];
                }
            }
            int newArea = largestRectangleArea(M[i]);
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
        
    }
};