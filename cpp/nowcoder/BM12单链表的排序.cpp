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
  ListNode *sortInList(ListNode *head) {
    vector<int> v;
    while (head) {
      v.push_back(head->val);
      head = head->next;
    }

    ListNode *res = new ListNode(-1);
    ListNode *cur = res;
    for (auto &val : v) {
      cur->next = new ListNode(val);
      cur = cur->next;
    }

    return res->next;
  }
};

class Solution2 {
public:
  ListNode *sortInList(ListNode *head) {
    if (!head || !head->next)
      return head;

    // slow node is the middle position of the list
    ListNode *fast = head->next, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = nullptr;

    ListNode *left = sortInList(head);
    ListNode *right = sortInList(tmp);

    ListNode *newHead = new ListNode(-1);
    ListNode *cur = newHead;

    while (left && right) {
      if (left->val < right->val) {
        cur->next = left;
        left = left->next;
      } else {
        cur->next = right;
        right = right->next;
      }
      cur = cur->next;
    }

    cur->next = left ? left : right;
    return newHead->next;
  }
};
