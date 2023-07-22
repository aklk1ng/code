#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Soluton {
public:
  ListNode *sortList(ListNode *head) {
    if (!head)
      return head;
    int len = 0;
    ListNode *node = head;
    while (node) {
      len++;
      node = node->next;
    }
    ListNode *dummy = new ListNode(-1, head);
    for (int sublen = 1; sublen < len; sublen <<= 1) {
      ListNode *prev = dummy, *cur = dummy->next;
      ListNode *head1 = cur;
      for (int i = 1; i < sublen && cur->next; i++)
        cur = cur->next;

      ListNode *head2 = cur->next;
      cur->next = nullptr;
      cur = head2;

      for (int i = 1; i < sublen && cur && cur->next; i++)
        cur = cur->next;

      ListNode *next = nullptr;
      if (cur) {
        next = cur->next;
        cur->next = nullptr;
        cur = next;
      }

      ListNode *merged = mergeList(head1, head2);
      prev->next = merged;
      while (prev->next)
        prev = prev->next;
      cur = next;
    }
    return dummy->next;
  }

  ListNode *mergeList(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy, *tmp1 = list1, *tmp2 = list2;

    while (tmp1 && tmp2) {
      if (tmp1->val < tmp2->val) {
        cur->next = tmp1;
        tmp1 = tmp1->next;
      } else {
        cur->next = tmp2;
        tmp2 = tmp2->next;
      }
      cur = cur->next;
    }
    cur->next = list1 == nullptr ? list2 : list1;
    return dummy->next;
  }
};
