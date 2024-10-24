/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 void makeParent(unordered_map<TreeNode*, TreeNode*>&mp, TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        mp[root->left] = root;
    }
    if (root->right) {
        mp[root->right] = root;
    }
    makeParent(mp, root->left);
    makeParent(mp, root->right);
    return;

 }
void solve(TreeNode* root, int &dist, int k, unordered_map<TreeNode*, TreeNode*>&mp, unordered_map<TreeNode*, int>&visited, vector<int>&ans) {
    
    if (dist == k && root != NULL) {
        ans.push_back(root->val);
        return;
    }
    if (root == NULL) {
        return;
    }
    dist ++;
    visited[root] ++;
    if (visited.find(visited[root->left]) == mp.end()) {
        solve(root->left, dist, k,mp, ans);

    }
    if (visited.find(root->right) == mp.end()) {
        solve(root->right, dist, k,mp, ans);

    }
    if (visited.find(mp[root]) == mp.end()) {
        solve(mp[root], dist, k,mp, ans);

    }
    
    // solve(root->left, dist, k,mp, ans);
    // solve(root->right, dist,k,mp,ans);
    // solve(mp[root], dist,k,mp,ans);
    dist--;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        int dist = 0;
        unordered_map<TreeNode*, TreeNode*>mp;
        unordered_map<TreeNode*, int>visited;
        mp[root] = NULL;
        makeParent(mp, root);

        solve(target, dist,k,mp,ans);
        if (dist >= k) {
            return ans;
        }
        else{
            return ans;

        }

        
    }
};