#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Soluton {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> set;
    while (head) {
      if (set.count(head))
        return true;
      set.insert(head);
      head = head->next;
    }
    return false;
  }
};
