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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *p0 = dummy;
    ListNode *cur = p0->next, *pre = nullptr;
    while (cur && cur->next) {
      for (int i = 0; i < 2; i++) {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      ListNode *tmp = p0;
      p0->next->next = cur;
      p0->next = pre;
      p0 = tmp;
    }
    return dummy->next;
  }
};
