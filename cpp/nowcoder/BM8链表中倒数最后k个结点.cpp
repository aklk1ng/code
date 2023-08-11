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
  ListNode *FindKthToTail(ListNode *pHead, int k) {
    ListNode *slow = pHead, *fast = pHead;
    while (k--) {
      if (!fast)
        return nullptr;
      fast = fast->next;
    }

    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }
};
