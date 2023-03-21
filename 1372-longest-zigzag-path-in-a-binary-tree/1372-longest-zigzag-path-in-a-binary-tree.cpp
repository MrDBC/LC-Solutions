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
    int maxlen=0;
    unordered_map<TreeNode*, vector<int>> dp;

public:
    // 0- root is left child , 1 - root is right child, (-1) - for the topmost node
    void dfs( TreeNode* root, int prev_direction, int prev_len){
        if( !root)
            return;
        int  leftlen=0, rightlen=0;
        // if( prev_direction != -1)
        // {}
        if( prev_direction == 0) // root is left child of its parent
            leftlen = 1+prev_len;
        if( prev_direction == 1) // rooot is the right child of its parent
            rightlen = 1+ prev_len;
        
        maxlen= max( maxlen , max(leftlen, rightlen));
        dfs(root->left, 0, rightlen);
        dfs(root->right, 1, leftlen);
    }
    int longestZigZag(TreeNode* root) {
        
        dfs(root, -1, 0);
        return maxlen;
    }
};