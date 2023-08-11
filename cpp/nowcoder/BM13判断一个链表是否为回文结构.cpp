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
  bool isPail(ListNode *head) {
    vector<int> v;
    while (head) {
      v.push_back(head->val);
      head = head->next;
    }
    for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
      if (v[i] != v[j])
        return false;
    }
    return true;
  }
};

class Solution2 {
public:
  bool isPail(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast)
      slow = slow->next;

    slow = reverse(slow);
    fast = head;

    while (slow) {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }
    return true;
  }

  ListNode *reverse(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *pre = nullptr;

    while (head) {
      ListNode *nxt = head->next;
      head->next = pre;
      pre = head;
      head = nxt;
    }
    return pre;
  }
};
