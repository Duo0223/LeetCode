class Solution
{
protected:
    ListNode* revert( ListNode *root )
    {
        ListNode *prev = NULL;
        ListNode *curr = root;
        ListNode *next = root->next;
        
        while (next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
    
public:
    bool isPalindrome(ListNode* head)
    {
        if( head == NULL ) return  true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            ++count;
        }
        
        slow = revert( slow );
        ListNode *secondHead = slow;
        while ( count > 0 )
        {
            if( head->val != secondHead->val )  return false;
            head = head -> next;
            secondHead = secondHead->next;
            --count;
        }
        return true;
    }
};