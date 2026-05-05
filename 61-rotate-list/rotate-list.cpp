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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || head->next == nullptr || k == 0) {
            return head;
        }
        ListNode* current = head;

        int n = 0;
        while (current != nullptr) {
            n = n + 1;
            current = current->next;
        }

        k = k % n;
        if (k == 0)
            return head;

        for (int i = 0; i < k; i++) {
            ListNode* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            ListNode* last = current->next;
            current->next = nullptr;
            last->next = head;
            head = last;
        }
        return head;
    }
};