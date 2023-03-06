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
    TreeNode* recoverFromPreorder(string tr) {
        stack<TreeNode* > st;
        
        
        for(int i=0; i<tr.size();){
            
            // calculate the depth
            int depth =0;
            while( tr[i]=='-' and ++i)
                ++depth;
            
            // calculate the integer number
            int num =0;
            while( i<tr.size() && tr[i]!= '-')
                num = num*10 + ( tr[i++] - '0' );
            
            // create a node with value = num
            TreeNode* node= new TreeNode(num);
            
            // while stack size > depth, pop nodes from stack
            // becoz we can only link the current "node" to it previous depth parent
            // so we need to pop , until stack size == depth
            
            while( !st.empty() and st.size() > depth)
                st.pop();
            
            // if parent's left child is null, assign current child "node" as left child
            if( !st.empty() and st.top()->left == NULL)
                st.top()->left = node;
            // if parent's left child is already assigned, it wont be null, right
            // so u need to assign parent's right child = current "node"
            else if( !st.empty() and st.top()->left != NULL)
                st.top()->right = node;
            
            st.push(node);
        }
        
        // we need to return root node, so pop all other nodes first
        while( st.size()> 1)
            st.pop();
        return st.top();
    }
};