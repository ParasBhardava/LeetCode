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
    ListNode* doubleIt(ListNode* head) {
        
        stack<ListNode*>st;
        ListNode *start = new ListNode(0);
        st.push(start);
        ListNode *temp = head;
        while(temp)
        {
            st.push(temp);
            temp = temp->next;
        }
        
        int carry = 0;
        while(!st.empty())
        {
            ListNode *curr = st.top();
            st.pop();
            int val = curr->val;
            curr->val = ((val * 2) + carry) % 10;
            carry = ((val * 2) + carry) / 10;
            
            if(!st.empty())
                st.top()->next = curr;
        }
        
        if(start->val == 0)
            start = start->next;
        
        return start;
        
    }
};