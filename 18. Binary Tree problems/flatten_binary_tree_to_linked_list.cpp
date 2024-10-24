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


//Approach 1 with extra space complexity(recursive)
class Solution {
public:
  void solve(TreeNode* &root, TreeNode* &prev) {
    if (root == NULL) {
        return ;
    }
    solve(root->right, prev);
    solve(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
    return;

  }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root, prev);

       
        
    }


    // Appraoch 2 space complexity is o(1) morris traversal

     void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev;
        while (curr != NULL) {
            if (curr->left != NULL) {
                prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
    }
};