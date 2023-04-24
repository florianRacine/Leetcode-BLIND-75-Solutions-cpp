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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* tmp = NULL;
        ListNode* node = head;
        while (node != NULL) {
            
            // Store the next node
            tmp = node -> next;

            // Point to the previous node
            node -> next = prev;

            // The current node becomes the previous node
            prev = node;

            // The current node becomes the old next node
            node = tmp;
            
        }
        return prev;
    }
};
