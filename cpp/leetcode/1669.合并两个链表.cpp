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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *slow = list1, *fast = list2;
    for (int i = 0; i < a - 1; i++)
      slow = slow->next;
    for (int i = 0; i < b + 1; i++)
      fast = fast->next;
    slow->next = list2;

    ListNode *pre = list2;
    while (pre->next)
      pre = pre->next;
    pre->next = fast;

    return list1;
  }
};
