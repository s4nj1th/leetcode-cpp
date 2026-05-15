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
        if (!head) return;

        ListNode* t = head;
        ListNode* h = head;
        while (h && h->next) {
            t = t->next;
            h = h->next->next;
        }

        ListNode* second = t->next;
        t->next = nullptr;
        ListNode* node = nullptr;

        while (second) {
            ListNode* front = second->next;
            second->next = node;
            node = second;
            second = front;
        }

        ListNode* first = head;
        second = node;

        while (second) {
            ListNode* front1 = first->next;
            ListNode* front2 = second->next;
            first->next = second;
            second->next = front1;
            first = front1;
            second = front2;
        }
    }
};
