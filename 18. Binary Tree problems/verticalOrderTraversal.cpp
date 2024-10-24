#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<bits/stdc++.h>

using namespace std;
 
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int ,multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        int lvl = 0;
        vector<vector<int>>ans;
        if (root == NULL) {
            return ans;
        }
        q.push(make_pair(root, make_pair(0,0)));
        while (!q.empty()) {
            pair<TreeNode*,pair<int,int>>p  = q.front();
            q.pop();
            TreeNode* frontNode = p.first;
            int lvl = p.second.second;
            int hd = p.second.first;
            mp[hd][lvl].insert(frontNode->val);
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd -1, lvl + 1)));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }
        for(auto i:mp){
			vector<int>ver;
			for(auto j:i.second){
				for(auto k:j.second) ver.push_back(k);
			}  
			ans.push_back(ver);
		}
        return ans;

        
    }
};