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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<pair<TreeNode*, pair<long long, long long>>> q;
        q.push({root, {LONG_MIN, LONG_MAX}});
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                long long left_limit = curr.second.first, right_limit = curr.second.second;
                
                if (node->val <= left_limit || node->val >= right_limit) {
                    return false;
                }
                
                if (node->left) {
                    q.push({node->left, {left_limit, node->val}});
                }
                if (node->right) {
                    q.push({node->right, {node->val, right_limit}});
                }
            }
        }
        return true;
    }
};
