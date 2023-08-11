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

    ListNode *fast = head->next, *slow = head;

    while (fast) {
      if (fast->val == slow->val)
        slow->next = fast->next;
      else
        slow = slow->next;

      fast = fast->next;
    }
    return head;
  }
};
