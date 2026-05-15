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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        int len = 0;
        ListNode* p = head;

        while (p) {
            len++;
            p = p->next;
        }

        int steps = len - n;

        ListNode* curr = &dummy;

        while (steps--) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return dummy.next;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        if (!fast)
            return head->next;

        while (fast->next)
            fast = fast->next, slow = slow->next;

        slow->next = slow->next->next;
        return head;
    }
};
