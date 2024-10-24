/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int dfs(TreeNode* root, int& ans) {
    if (root == NULL) {
        return 0;
    }
    int maxLeft = dfs(root->left, ans);
    int maxRight = dfs(root->right, ans);
    maxLeft = max(maxLeft, 0);
    maxRight = max(maxRight, 0);
     ans = max(ans, root->val + maxLeft + maxRight);
    return root->val + max(maxLeft, maxRight);
    

}
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
        
    }
};