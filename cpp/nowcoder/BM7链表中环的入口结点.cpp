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
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    if (!pHead)
      return nullptr;

    ListNode *slow = pHead, *fast = pHead;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        break;
    }

    if (!fast || !fast->next)
      return nullptr;
    fast = pHead;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};

class Solution2 {
public:
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    unordered_set<ListNode *> set;
    while (pHead) {
      if (set.count(pHead))
        return pHead;
      set.insert(pHead);
    }

    return nullptr;
  }
};
