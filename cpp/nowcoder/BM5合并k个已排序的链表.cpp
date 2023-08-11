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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    return divideMerge(lists, 0, lists.size() - 1);
  }

  ListNode *divideMerge(vector<ListNode *> &lists, int left, int right) {
    if (left < right)
      return nullptr;
    else if (left == right)
      return lists[left];

    int mid = (left + right) / 2;
    return merge(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
  }

  ListNode *merge(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    ListNode *l1 = list1, *l2 = list2;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    cur->next = l1 ? l1 : l2;
    return dummy->next;
  }
};

class Solution2 {
public:
  struct cmp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    for (auto &list : lists)
      if (list)
        pq.push(list);

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;

    while (!pq.empty()) {
      ListNode *tmp = pq.top();
      pq.pop();
      cur->next = tmp;
      cur = cur->next;

      if (tmp->next)
        pq.push(tmp->next);
    }
    return dummy->next;
  }
};
