#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c) {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};
class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;

    }

};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
    
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, Compare>pq;
        for (int i = 0; i < k; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(new Node(nums[i][0], i, 0));

        }
        int start = mini, end = maxi;
        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            mini = top->data;
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (top->col + 1 < nums[top->row].size()) {
                maxi = max(maxi, nums[top->row][top->col + 1]);
                Node* temp = new Node(nums[top->row][top->col + 1], top->row, top->col + 1);
                pq.push(temp);
            }
            else {
                break;
            }
        }
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
        
    }
};