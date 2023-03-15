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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int h=0;
        while( !q.empty()){
            int currLevelNodes = pow(2,h);
            
            int sz = q.size();
            bool incompleteNode = false;
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                --currLevelNodes;
                q.pop();
                    
                // at the same level, we have nodes to the left which are incomplete
                // and this node(on the right) has children, 
                // or
                // curr node has right child but no left child
                // return false
                if( (incompleteNode and ( curr->right or curr->left)) || (!curr->left and curr->right))
                    return false;
                
                // just checking whether any node to the left doesnt have 2 children
                if( !curr->left or !curr->right)
                    incompleteNode = true;
                
                if( curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                
            }
            ++h;
            
            // we could have less than 2^h nodes only at the last level
            if( !q.empty() and currLevelNodes!=0)
                return false;
        }
        
        return true;
    }
};