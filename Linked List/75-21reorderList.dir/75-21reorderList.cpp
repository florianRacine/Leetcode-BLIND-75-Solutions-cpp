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
    void reorderList(ListNode* head) {
        if (head -> next == NULL || head -> next -> next == NULL) return ;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast != NULL && (fast -> next) != NULL) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }
        // Slow is pointing to the midle
        ListNode* node = slow -> next;
        ListNode* prev_node = slow;
        while (true) {
            // We stock the next node
            ListNode* tmp = node -> next;

            // We point to the previous node
            node -> next = prev_node;

            if (tmp == NULL) break;

            // The current node become the previous node
            prev_node = node;

            // The current node go to the old next node
            node = tmp;
        }

        ListNode* tmp = slow -> next;
        slow -> next = NULL;
        tmp -> next = NULL;

        ListNode* left = head;
        ListNode* right = node;
        while (left -> next != NULL && right != NULL) {
            ListNode* tmp_left = left -> next;
            ListNode* tmp_right = right -> next;

            left -> next = right;
            right -> next = tmp_left;

            left = tmp_left;
            right = tmp_right;
        }
        left -> next = right;
        return ;
    }
};
