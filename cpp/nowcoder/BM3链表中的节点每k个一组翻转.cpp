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
    ListNode *tail = head;

    for (int i = 0; i < k; i++) {
      if (!tail)
        return head;
      tail = tail->next;
    }

    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != tail) {
      ListNode *tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }

    head->next = reverseKGroup(tail, k);
    return pre;
  }
};
