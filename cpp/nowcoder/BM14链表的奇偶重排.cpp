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
  ListNode *oldEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *odd = head, *even = head->next;
    ListNode *evenhead = even;

    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }

    odd->next = evenhead;
    return head;
  }
};
