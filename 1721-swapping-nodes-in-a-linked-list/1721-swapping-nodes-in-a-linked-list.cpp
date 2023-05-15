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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* curr,  *slow= head, *fast = head;
        while( --k)
            fast=fast->next;
        
        curr= fast->next;
        while( curr)
            curr= curr->next, slow= slow->next;
        
        swap(slow->val, fast->val);
        
        return head;
    }
};