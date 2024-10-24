#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL) {
            return ans;
        }
        
        queue<TreeNode*>q;
        int flag = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int>temp(q.size());
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* Node = q.front();
                q.pop();
                int index;
                if (flag == 0) {
                    index = i;
                }
                else {
                    index = sz - i - 1;
                }
                temp[index] = Node->val;
                if (Node->left) {
                    q.push(Node->left);
                }
                if (Node->right) {
                    q.push(Node->right);
                }
            }
            flag = !flag;
            ans.push_back(temp);
            


        }
        return ans;
        
    }
};