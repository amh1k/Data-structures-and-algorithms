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
void solve(TreeNode* root, int k, int &ans, int &count) {
    if (root == NULL) {
        return;
    }
    solve(root->left, k, ans, count);
    count ++;
    if (count == k) {
        ans = root->val;
    }
    solve(root->right, k, ans, count);

}
    int kthSmallest(TreeNode* root, int k) {
        int ans  = -1;
        int count = 0;
        solve(root, k, ans, count);
        return ans;
        
    }
};