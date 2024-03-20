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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *current1 = list1, *current2 = list1;
        for(int i = 0; i < a - 1; i++)
            current1 = current1->next;
        
        for(int i = 0; i < b; i++)
            current2 = current2->next;
        
        current1->next = list2;
        while(list2->next)
            list2 = list2->next;
        
        list2->next = current2->next;
        return list1;
    }
};