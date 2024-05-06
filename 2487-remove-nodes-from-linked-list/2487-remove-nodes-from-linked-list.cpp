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
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = new ListNode(INT_MAX);
        stack<ListNode*> st;
        st.push(temp);
        
        while(head != NULL)
        {
            while(st.top()->val < head->val)
                st.pop();
            
            st.top()->next = head;
            st.push(head);
            head= head->next;
        }
        return temp->next;
    }
};