#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
  }
};