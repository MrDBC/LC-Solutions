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
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* end= nullptr) {
        // just note end is not our end within our current window
        // it is the starting of the next window
        // basically in our current winodw, we start at head & finish at (end-1)
        
        // this means we have crossed our window, so return nullptr
        if( head== end)
            return nullptr;
        
        // just to get the middle node
        ListNode* slow = head, *fast = head;
        while( fast != end and fast->next!= end){
            slow = slow->next;
            fast=fast->next->next;
        }
        
        // after gettting middle listnode, make it a treenode 
        // and recursively form its left and right subtree
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow); // our window = [head.....(slow-1)]
        root->right = sortedListToBST(slow->next, end); // our window = [slow+1.... end-1]
        
        return root;
    }
};