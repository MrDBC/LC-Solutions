/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool ispresent = false;
    ListNode* llhead;
public:
    void dfs( ListNode* head, TreeNode* root, int prevmatched){
        if( !head){
            ispresent = true;
            return;
        }
        
        if( !root)
            return;
        
        int llval= head->val, treeval = root->val;
        if( llval == treeval and ((head==llhead and prevmatched==0) or  prevmatched==1)){
            // case 1: match it, and send a search team for the next ll node , in the left subtrree
            dfs(head->next, root->left, 1);
            // case 2: match it, and send a search team for the next ll node , in the right subtrree
            dfs( head->next, root->right, 1);
            
            //case 3: 
            dfs( head, root->left, 0);
            dfs(head, root->right, 0);
        }
        else{
            dfs( head, root->left, 0);
            dfs(head, root->right, 0);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        llhead=head;
        dfs( head, root, 0);
        return ispresent;
    }
};