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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        if (!root ) {
            return 0;
        }
        
        int ans = 0;
       
        while (!q.empty()) {
            int size = q.size();
            int minn = q.front().second;
             int start, last;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front().first;
                long long  index = q.front().second - minn;
                q.pop();
                if (i == 0) start = index;
                if (i == size - 1) last = index;
                if (front->left) {
                    q.push({front->left, 2 * index + 1 });
                }
                if (front->right) {
                    q.push({front->right, 2 * index + 2});
                }


            }
            ans = max(ans, last - start + 1 );

        }
        return ans;
    }
};