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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
     
        vector<ListNode*>ans(k, nullptr);
        ListNode *temp = head;
        
        int totalSize = 0;
        while(temp != nullptr)
        {
            totalSize++;
            temp = temp->next;
        }
        
        int size = totalSize/k;
        int distribute = totalSize%k;
        
        ListNode *node = head;
        ListNode *prev = nullptr;
        int i = 0;
        while(node != nullptr && i<k)
        {
            ans[i] = node;
            for(int j = 0; j<size + (distribute > 0 ? 1 : 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
            i++;
            distribute--;
        }
        
        return ans;
    }
};