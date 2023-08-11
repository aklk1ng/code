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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *res = new ListNode(-1, head);
    ListNode *cur = res;

    while (cur->next && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        int tmp = cur->next->val;
        while (cur->next && cur->next->val == tmp)
          cur->next = cur->next->next;
      } else
        cur = cur->next;
    }

    return res;
  }
};
