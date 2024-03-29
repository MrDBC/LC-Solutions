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
    string dfs( TreeNode* root){
        if( !root)
            return "";
        
        string res="("+ to_string(root->val); // (2   
        string left = dfs(root->left);
        string right = dfs(root->right);
        
        if( left=="" and right!="")
            left="()";
        return  res+left+right+  ")";
        
    }
    string tree2str(TreeNode* root) {
        string res= dfs(root);
        res.pop_back();
        return res.substr(1);
    }
};