class Solution {
public:
  int getDecimalValue(ListNode *head) {
    ListNode *p = head;
    int sum = 0;

    while (p) {
      sum *= 2;
      sum += p->val;

      p = p->next;
    }

    return sum;
  }
};