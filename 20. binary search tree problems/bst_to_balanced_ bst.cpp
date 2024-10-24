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
  void inOrder(TreeNode* root, vector<int>&in) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
  }
  TreeNode* buildTree(vector<int>& ans, int s, int e) {
    if (s > e) {
        return NULL;
    }
    int mid = s + (e-s) /2;
    TreeNode* root = new TreeNode(ans[mid]);
    root->left = buildTree(ans, s, mid - 1);
    root->right = buildTree(ans, mid + 1, e);
    return root;
  }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inOrder(root, in);
        return buildTree(in, 0, in.size() - 1);
        
        
    }
};