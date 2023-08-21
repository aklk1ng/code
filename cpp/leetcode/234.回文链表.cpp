#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(-1), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *cur = head, *pre = nullptr;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  bool isPalindrome(ListNode *head) {
    if (!head->next)
      return true;
    ListNode *mid = middleNode(head);
    if (!mid->next) {
      if (head->val == head->next->val)
        return true;
      else
        return false;
    }

    ListNode *head2 = reverse(mid);
    ListNode *l1 = head, *l2 = head2;
    while (l1 && l2) {
      if (l1->val != l2->val)
        return false;
      l1 = l1->next;
      l2 = l2->next;
    }
    return true;
  }
};
