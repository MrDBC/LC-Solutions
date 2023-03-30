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
    // int total=0;
public:
    void dfs( TreeNode* root, int& total){
        if( !root)
            return;
        
        dfs( root->right, total);
        root->val+= total;
        total= root->val; // 15, 21
        
        dfs( root->left, total);
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        // CALL RIGHT subtree, return its sum
        // add that sum to current rootnode
        // return this for the left subtree
        int total=0;
        dfs( root, total);
        return root;
        
    }
};