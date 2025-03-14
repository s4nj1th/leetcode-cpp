class Solution {
public:
  ListNode *shiftBy1(ListNode *head) {
    ListNode *p = head, *prev = nullptr;
    while (p->next != nullptr) {
      prev = p;
      p = p->next;
    }
    prev->next = nullptr;
    p->next = head;
    head = p;
    return head;
  }

  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0)
      return head;
    ListNode *p = head;
    int n = 1;
    while (p->next != nullptr) {
      p = p->next;
      n++;
    }
    for (int i = 0; i < k % n; i++) {
      head = shiftBy1(head);
    }
    return head;
  }
};