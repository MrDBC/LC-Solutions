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
    int postIdx ;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= postorder.size();
        postIdx= n-1;
        
        return dfs(inorder, 0, n-1, postorder);
    }
    
    TreeNode* dfs(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder){
        
        if( in_left > in_right)
            return nullptr;
        int root_val = postorder[postIdx--];
        TreeNode* root = new TreeNode(root_val);
        
        int i;
        for( i=in_left; i<=in_right; i++)
            if( inorder[i]== root_val)
                break;
        
        root->right = dfs(inorder, i+1, in_right, postorder);
        root->left = dfs(inorder, in_left, i-1, postorder);
        
        return root;
    }
};