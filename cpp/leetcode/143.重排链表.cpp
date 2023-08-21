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
  ListNode *reverse(ListNode *head) {
    ListNode *cur = head, *pre = nullptr;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  void reorderList(ListNode *head) {
    ListNode *mid = middleNode(head);
    ListNode *head2 = reverse(mid);
    while (head2->next) {
      ListNode *nxt = head->next, *nxt2 = head2->next;
      head2->next = head->next;
      head->next = head2;
      head = nxt;
      head2 = nxt2;
    }
  }
};
