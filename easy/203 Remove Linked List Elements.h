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
    ListNode* removeElements(ListNode* head, int val)
    {
        if( head == NULL )  return head;
        
        while( head != NULL && head->val == val )
        {
            ListNode *tmp = head;
            head = tmp->next;
            delete tmp;
        }
        if( head != NULL )
        {
            ListNode *curr = head->next;
            ListNode *prev = head;
            while( curr != NULL )
            {
                if(curr->val == val)
                {
                    ListNode *tmp = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    delete tmp;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};