class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;

    ListNode *t = head;
    ListNode *h = head;

    while (h != nullptr && h->next != nullptr) {
      t = t->next;
      h = h->next->next;
      if (t == h)
        return true;
    }

    return false;
  }
};