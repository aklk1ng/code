#include <bits/stdc++.h>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Soluton1 {
public:
  ListNode *deleteNode(ListNode *head, int val) {
    if (head->val == val)
      return head;
    ListNode *pre = head, *cur = head->next;
    while (cur && cur->val != val) {
      pre = cur;
      cur = cur->next;
    }
    // 找到了节点
    if (cur)
      pre->next = cur->next;
    return head;
  }
};

class Soluton2 {
public:
  ListNode *deleteNode(ListNode *head, int val) {
    if (head == nullptr)
      return head;
    if (head->val == val)
      return head->next;

    head->next = deleteNode(head->next, val);
    return head;
  }
};
