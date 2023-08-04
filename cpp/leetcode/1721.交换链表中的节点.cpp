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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *fast = head;
    for (int i = 1; i < k; i++)
      fast = fast->next;

    ListNode *tmp = fast;
    ListNode *slow = head;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    swap(tmp->val, slow->val);
    return head;
  }
};
