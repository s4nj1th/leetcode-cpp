class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
      return nullptr;
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
      pA = (pA == nullptr) ? headB : pA->next;
      pB = (pB == nullptr) ? headA : pB->next;
    }
    return pA;
  }
};