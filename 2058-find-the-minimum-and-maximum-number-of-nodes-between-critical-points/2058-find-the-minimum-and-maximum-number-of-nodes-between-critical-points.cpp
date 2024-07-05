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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        head = head->next;
        int i = 1, first = INT_MAX, last = 0, mini = INT_MAX;
        while(head->next)
        {
            if((head->val > prev->val && head->val > head->next->val) ||
               ( head->val < prev->val && head->val < head->next->val))
            {
                if (last != 0)
                    mini = min(mini, i - last);
                first = min(first, i);
                last = i;
            }
            prev = head;
            head = head->next;
            i++;
        }
        
        if (mini == INT_MAX)
            return {-1, -1};
        
        int maxi = last - first;
        return {mini, maxi};

    }
};