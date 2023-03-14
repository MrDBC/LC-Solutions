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
    int total =0;
public:

    void dfs(TreeNode* root, int curr_val){
        if( !root)
            return ;
        
        curr_val = curr_val * 10 + root->val;
        
        if( !root->left and !root->right){
            total+= curr_val;
            return;
        }
        dfs(root->left, curr_val);
        dfs(root->right, curr_val);
    }
    int sumNumbers(TreeNode* root) {
        
        if( !root)
            return 0;
        
        dfs(root, 0);
        return total;
    }
};