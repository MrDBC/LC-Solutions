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
    int totalNodes ;
public:
    bool isCompleteTree(TreeNode* root) {
        totalNodes = count(root);
        return dfs(root,0);
    }
    bool dfs(TreeNode* root, int idx){
        if( !root)
            return true;
        if( idx >= totalNodes)
            return false;
        return dfs(root->left, idx*2+1) and dfs(root->right, idx*2+2);
    }
    int count(TreeNode* root){
        if( !root)
            return 0;
        return 1+ count(root->left) + count(root->right);
    }
};