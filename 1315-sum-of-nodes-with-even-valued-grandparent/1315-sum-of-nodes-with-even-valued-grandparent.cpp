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
    int sum=0;
public:
    void dfs( TreeNode* root,int p, int gp){
        if( !root)
            return;
        
        if( gp!= -1 and gp%2==0)
            sum+= root->val;
        dfs(root->left, root->val, p );
        dfs(root->right, root->val, p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, -1, -1);
        return sum;
    }
};