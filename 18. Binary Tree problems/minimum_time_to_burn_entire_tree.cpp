/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void createMap(TreeNode* root, int start, unordered_map<Node*, Node*>& mp,
                   TreeNode* target) {
        if (root == NULL) {
            return;
        }
        if (root > val = start) {
            target = root;
        }

        if (root->left) {
            mp[root->left] = root;
        }
        if (root->right) {
        mp[root->right = root;
        }
        createMap(root->left, start, mp);
        createMap(root->right, start, mp);
    }
    void solve(TreeNode* target, unordered_map<Node*, Node*>& mp, int& ans, unordered_map<Node*, bool>visited) {
        queue<Node*> q;
        q.push(target);
        while (!q.empty()) {
            bool flag = 0;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push_back(node->left);
                    flag = 1;
                }
                 if (node->left && !visited[node->right]) {
                    q.push_back(node->left);
                    flag = 1;
                }
                 if (mp[node] && !visited[mp[node]]) {
                    q.push_back(node->left);
                    flag = 1;
                }
            }
            if (flag == 1) {
                ans ++;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target = createMap(TreeNode * root, int start, mp);
    }
};