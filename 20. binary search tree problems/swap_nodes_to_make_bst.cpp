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
   TreeNode* prev;
   TreeNode* first;
   TreeNode* last;
   TreeNode* middle;
   void solve(TreeNode* root)  {
    if (root == NULL) {
        return;

    }
    solve(root->left);
    if (prev != NULL && root->val < prev->val) {
        if (first == NULL) {
            first = prev;
            middle = root;
        }
        else {
            last = root;
        }
    }
    prev = root;
    solve(root->right);
   }
    void recoverTree(TreeNode* root) {
        first = middle = last = prev =  NULL;
        solve(root);
        if (first != NULL && last != NULL){
            swap(first->val, last->val);
        }
        else {
            swap(first->val, middle->val);
        }
        
    }
};