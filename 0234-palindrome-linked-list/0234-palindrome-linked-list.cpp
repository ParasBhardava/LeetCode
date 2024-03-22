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
private:
    ListNode* reverseList(ListNode *head)
    {
         ListNode *prev = NULL, *next = NULL;
            while(head != NULL)
            {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }

            return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
     
        if(head == NULL && head->next == NULL)
            return true;
        
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow != NULL)
        {
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};