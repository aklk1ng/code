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
  ListNode *addInList(ListNode *head1, ListNode *head2) {
    if (!head1)
      return head2;
    if (!head2)
      return head1;

    head1 = reverse(head1);
    head2 = reverse(head2);

    ListNode *newHead = new ListNode(-1);
    ListNode *cur = newHead;

    int tmp = 0;
    while (head1 || head2) {
      int val = tmp;

      val += head1 ? head1->val : 0;
      val += head2 ? head2->val : 0;

      tmp = val / 10;
      cur->next = new ListNode(val % 10);
      cur = cur->next;
    }

    if (tmp > 0)
      cur->next = new ListNode(tmp);

    return reverse(newHead);
  }

  ListNode *reverse(ListNode *head) {
    if (!head)
      return nullptr;
    ListNode *pre = head, *cur = head;

    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
};
