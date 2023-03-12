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
// class Solution {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists) {
//     if(lists.empty()){
//         return nullptr;
//     }
//     while(lists.size() > 1){
//         lists.push_back(mergeTwoLists(lists[0], lists[1]));
//         lists.erase(lists.begin());
//         lists.erase(lists.begin());
//     }
//     return lists.front();
// }
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//     if(l1 == nullptr){
//         return l2;
//     }
//     if(l2 == nullptr){
//         return l1;
//     }
//     if(l1->val <= l2->val){
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     }
//     else{
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//     }
// }
// };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            
            // if len was odd, we didnt work on the middle list
            // so we can work on it in the next iteration
            // for eg: if len=3, then only lists 1 & 3 got merged
            // and list2 wasnt touched
            // so now in the next iteration , len =(3+1)/2 = 2
            // so we are considering list 1( combined of 1 & 3) in previoius iteration
            // and list 2 
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};