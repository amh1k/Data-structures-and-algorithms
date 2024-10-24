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

//Same approach as max path sum
class Solution {
public:
int  solve(TreeNode* root,int & maxH) {
    if (root == NULL) {
       return 0;
    }
    int leftH = solve(root->left, maxH);
    int  rightH = solve(root->right, maxH);
    maxH = max(maxH, leftH + rightH);
    return 1 + max(leftH, rightH);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxH = 0;
        int temp = solve(root, maxH);
        return maxH;
        
    }
};