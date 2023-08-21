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
  ListNode *reverseKGroup(ListNode *head, int k) {
    int n = 0;
    ListNode *cur = head;
    while (cur) {
      n++;
      cur = cur->next;
    }
    ListNode *dummy = new ListNode(-1, head);
    ListNode *p0 = dummy;

    ListNode *pre = nullptr;
    cur = p0->next;
    while (n >= k) {
      n -= k;
      for (int i = 0; i < k; i++) {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      ListNode *tmp = p0->next;
      p0->next->next = cur;
      p0->next = pre;
      p0 = tmp;
    }
    return dummy->next;
  }
};
