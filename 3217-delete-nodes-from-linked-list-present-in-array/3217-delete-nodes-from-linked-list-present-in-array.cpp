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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode *res = new ListNode(0);
        unordered_set<int>st;
        for(auto it : nums)
            st.insert(it);
        
        if(head == nullptr)
            return head;
        
        while(head!=nullptr && st.count(head->val))
        {
            head = head->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr)
        {
            if(st.count(curr->val))
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            
            else
            {
                prev = curr;
                curr = curr->next;        
            }
        }
        
        return head;
        
    }
};