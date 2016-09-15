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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0 , lenB = 0;
        
        ListNode *tmpA = headA;
        while( tmpA != NULL )
        {
            ++lenA;
            tmpA = tmpA->next;
        }
        ListNode *tmpB = headB;
        while( tmpB != NULL )
        {
            ++lenB;
            tmpB = tmpB->next;
        }
        
        tmpA = headA;
        tmpB = headB;
        if( lenA > lenB )
        {
            int offset = lenA - lenB;
            while ( offset > 0 )
            {
                --offset;
                tmpA = tmpA -> next;
            }
        }
        else if( lenB > lenA )
        {
            int offset = lenB - lenA;
            while ( offset > 0 )
            {
                --offset;
                tmpB = tmpB -> next;
            }
            
        }
        while (tmpA != NULL && tmpB != NULL )
        {
            if( tmpA == tmpB )  return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return NULL;
    }
};