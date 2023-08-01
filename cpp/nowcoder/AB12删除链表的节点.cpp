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
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode *cur = head, *pre = head;
    if (head->val == val) {
      head = head->next;
      return head;
    }
    while (cur) {
      if (cur->val == val) {
        pre->next = cur->next;
      }
      pre = cur;
      cur = cur->next;
    }
    return head;
  }
};
