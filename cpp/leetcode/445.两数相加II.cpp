#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
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

  ListNode *addTwo(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      carry += l1 ? l1->val : 0;
      carry += l2 ? l2->val : 0;
      cur->next = new ListNode(carry % 10);
      cur = cur->next;
      carry /= 10;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return dummy->next;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    auto l3 = addTwo(l1, l2);
    return reverse(l3);
  }
};
