class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *p = head;

    while (p->next) {
      if (p->val == p->next->val)
        p->next = p->next->next;
      else
        p = p->next;
    }

    return head;
  }
};