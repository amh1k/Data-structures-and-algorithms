#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
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
  TreeNode* solve(vector<int>&preOrder, int min, int max, int &i) {
    if (i >= preOrder.size()) {
        return NULL;
    }
    if (preOrder[i]  < min || preOrder[i] > max) {
        return NULL;
    }
    int val = preOrder[i++];
    TreeNode* root = new TreeNode(val);
    root->left = solve(preOrder, min, val, i);
    root->right = solve(preOrder,val ,max, i);
    return root;
  }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int i = 0;
        return solve(preorder, INT_MIN, INT_MAX, i);
        
    }
};