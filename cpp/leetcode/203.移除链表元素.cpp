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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *cur = dummy;
    while (cur->next) {
      if (cur->next->val == val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }
    return dummy->next;
  }
};
