class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *secondHalf = reverseList(slow);
    ListNode *firstHalf = head;

    while (secondHalf != nullptr) {
      if (firstHalf->val != secondHalf->val) {
        return false;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return true;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }
    return prev;
  }
};

/* old code (lower time but higher memory)*/
class Solution {
  bool isPal(vector<int> &arr, int i, int j, int n) {
    while (i >= 0 && j < n) {
      if (arr[i] != arr[j])
        return false;
      i--;
      j++;
    }
    return true;
  }

public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr)
      return false;
    ListNode *p = head;
    vector<int> vals;
    while (p != nullptr) {
      vals.push_back(p->val);
      p = p->next;
    }
    int n = vals.size();
    int i = (n % 2 == 0) ? n / 2 - 1 : n / 2;
    int j = (n % 2 == 0) ? n / 2 : n / 2;
    return isPal(vals, i, j, n);
  }
};