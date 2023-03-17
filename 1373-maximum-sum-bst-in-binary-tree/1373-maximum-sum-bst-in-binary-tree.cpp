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
    int maxSum=0;
    
public:
    pair<bool, vector<int>> dfs( TreeNode* root){
        if( !root)
            return {true, {0, INT_MAX, INT_MIN}};
        
        auto left = dfs(root->left);
        auto right =dfs (root->right);
        
        // 3 information: whether subtree is  BST, minmax of both left & right subtrees
        if(!left.first  or !right.first) // if none of the subtres is a BST, return 0 as sum
            return {false, {}};
        
        int currVal = root->val; // 3
        int leftmin = left.second[1], leftmax= left.second[2]; // 2 2
        int rightmin = right.second[1], rightmax= right.second[2]; // 4 6
        int leftsum = left.second[0], rightsum= right.second[0]; // 2, 15
        
        int currSum = currVal; // 3
       
        // to state that bst rooted at current node = "root"
        // both its left & right subtrees should also be valid BSTs
        if(currVal> leftmax  and currVal< rightmin ) {
            currSum += leftsum+rightsum; // 3 + 2 + 15 = 20
            maxSum = max( maxSum, currSum);
        }
        // if not, then whole subtree roote at node="root" cant form a BST at all
        // so return false
        else
           return {false, {}};
        
        return {true, {currSum, min(currVal, leftmin), max( currVal, rightmax)}};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};