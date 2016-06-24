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
    ListNode* reverseList(ListNode* head) 
	{	
		if( head == NULL ) 
			return NULL;
		
        ListNode *next = head->next;
		head->next = NULL;
		while( next != NULL )
		{
			ListNode *tmp = next->next;
			next->next = head;
			head = next;
			next = tmp;
		}
		return head;
    }
};