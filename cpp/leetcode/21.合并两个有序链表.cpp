#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *preHead = new ListNode(-1);
    ListNode *prev = preHead;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }
    prev->next = list1 == nullptr ? list2 : list1;
    return preHead;
  }
};
