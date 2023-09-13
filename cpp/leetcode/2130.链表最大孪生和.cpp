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
  int pairSum(ListNode *head) {
    vector<int> v;
    int ans = 0;
    ListNode *cur = head;
    while (cur) {
      v.push_back(cur->val);
      cur = cur->next;
    }
    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
      ans = max(ans, v[i] + v[n - 1 + i]);
    }
    return ans;
  }
};

class Solution2 {
public:
  int pairSum(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *last = slow->next;
    while (last->next) {
      ListNode *cur = last->next;
      last->next = cur->next;
      cur->next = slow->next;
      slow->next = cur;
    }

    int ans = INT_MIN;
    ListNode *l1 = head, *l2 = slow->next;
    while (l2) {
      ans = max(ans, l1->val + l2->val);
      l1 = l1->next;
      l2 = l2->next;
    }
    return ans;
  }
};
