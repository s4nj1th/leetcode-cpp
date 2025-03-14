class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;
    ListNode *T = head, *H = head;
    bool cycle = false;
    while (H != nullptr && H->next != nullptr) {
      T = T->next;
      H = H->next->next;
      if (T == H) {
        cycle = true;
      };
      if (cycle) {
        ListNode *start = head;
        while (start != T) {
          start = start->next;
          T = T->next;
        }
        return start;
      }
    }
    return nullptr;
  }
};