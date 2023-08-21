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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *p0 = dummy;
    for (int i = 0; i < left - 1; i++)
      p0 = p0->next;

    ListNode *cur = p0->next;
    ListNode *pre = nullptr;
    for (int i = left; i <= right; i++) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    p0->next->next = cur;
    p0->next = pre;
    return dummy->next;
  }
};
