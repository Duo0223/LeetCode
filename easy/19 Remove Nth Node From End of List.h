/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
    Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode *curr = head;
		ListNode *prev = head;
		ListNode *tail = curr -> next;
		for( int i = 1 ; i < n ; ++i ) 
			tail = tail -> next;
		
		while( tail != NULL )
		{
			prev = curr;
			curr = curr->next;
			tail = tail->next;
		}
		if( curr == head )
		{
			head = curr->next;
			delete curr;
			curr = NULL;
		}
		else
		{
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
			curr = NULL;
		}
		return head;
    }
};