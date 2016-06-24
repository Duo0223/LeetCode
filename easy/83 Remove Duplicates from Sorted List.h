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
    ListNode* deleteDuplicates(ListNode* head) 
	{
		if( head == NULL ) return NULL;
		
		ListNode *current = head;
		ListNode *tmp = NULL;
		while(  current->next != NULL )
		{
			if( current->val == current->next->val )
			{
				tmp = current->next;
				current->next = current->next->next;
				delete tmp;
			}
			else
				current = current->next;
		}
		return head;
    }
};