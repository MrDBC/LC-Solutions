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
    
    TreeNode* bstFromPreorder(vector<int>& preorder, int i=0, int j=-1) {
        if( j==-1)
            j=preorder.size()-1;
        
        if( i>j)
            return NULL;
        
        int root_val = preorder[i], k;
        for(k=i+1; k<=j; k++)
            if( preorder[k]>root_val)
                break;
        
        
        TreeNode* root = new TreeNode(preorder[i]);
        root->left = bstFromPreorder(preorder, i+1, k-1);
        root->right = bstFromPreorder( preorder, k, j);
        
        return root;
    }
};