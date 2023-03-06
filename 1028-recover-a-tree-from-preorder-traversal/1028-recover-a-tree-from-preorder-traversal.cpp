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
    int i =0;
public:
    TreeNode* dfs( string tr, int depth){
        int no_of_dash = 0;
        
        while( (i + no_of_dash)< tr.size() and tr[i+no_of_dash]=='-')
            ++no_of_dash;
        
        // we got the no of dashes, now check if depth == no_of_dashes
        // if not we wont proceed further and return null
        // this happens first at "--4" point, when we are expecting a depth of 
        // 3 ( becoz previous node=3 (with a depth of 2)), but since 
        // 4 is a sibling and not a child of 3, we return null for 3's left child
        // as well as right child too
        if( no_of_dash != depth)
            return NULL;
        
        // u can safely update 'i' becoz we are at the correct depth
        i+= no_of_dash;
        
        // get the integer number
        int start_idx_num = i, num_size=0;
        while( i<tr.size()  and tr[i]!= '-' and ++i)
            ++num_size;
        
        TreeNode* node = new TreeNode( stoi(tr.substr(start_idx_num, num_size)));
        
        node->left = dfs(tr, depth+1);
        node->right = dfs(tr, depth +1);
        
        return node;
        
    }
    TreeNode* recoverFromPreorder(string tr) {
        
        return dfs( tr, 0);
//         stack<TreeNode* > st;
        
        
//         for(int i=0; i<tr.size();){
            
//             // calculate the depth
//             int depth =0;
//             while( tr[i]=='-' and ++i)
//                 ++depth;
            
//             // calculate the integer number
//             int num =0;
//             while( i<tr.size() && tr[i]!= '-')
//                 num = num*10 + ( tr[i++] - '0' );
            
//             // create a node with value = num
//             TreeNode* node= new TreeNode(num);
            
//             // while stack size > depth, pop nodes from stack
//             // becoz we can only link the current "node" to it previous depth parent
//             // so we need to pop , until stack size == depth
            
//             while( !st.empty() and st.size() > depth)
//                 st.pop();
            
//             // if parent's left child is null, assign current child "node" as left child
//             if( !st.empty() and st.top()->left == NULL)
//                 st.top()->left = node;
//             // if parent's left child is already assigned, it wont be null, right
//             // so u need to assign parent's right child = current "node"
//             else if( !st.empty() and st.top()->left != NULL)
//                 st.top()->right = node;
            
//             st.push(node);
//         }
        
//         // we need to return root node, so pop all other nodes first
//         while( st.size()> 1)
//             st.pop();
//         return st.top();
    }
};