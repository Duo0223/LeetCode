/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if( head == NULL || head->next == NULL )
            return head;
        
        ListNode *current = head;
        while (current != NULL && current->next != NULL )
        {
            int tmp = current->val;
            current->val = current->next->val;
            current->next->val = tmp;
            current = current->next->next;
        }
        return head;
    }
};