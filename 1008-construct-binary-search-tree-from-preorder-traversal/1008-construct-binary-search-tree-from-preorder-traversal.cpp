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
    TreeNode* dfs( vector<int>& preorder, int i, int j){
        if( i>j)
            return NULL;
        
        int root_val = preorder[i], k;
        for(k=i+1; k<=j; k++)
            if( preorder[k]>root_val)
                break;
        
        
        TreeNode* root = new TreeNode(preorder[i]);
        root->left = dfs(preorder, i+1, k-1);
        root->right = dfs( preorder, k, j);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return dfs( preorder, 0, preorder.size()-1);
    }
};