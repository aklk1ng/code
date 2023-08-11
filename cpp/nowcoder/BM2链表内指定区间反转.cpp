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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || !head->next)
      return head;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *pre = dummy;
    for (int i = 0; i < m; i++)
      pre = pre->next;
    ListNode *cur = cur->next;

    // cur：指向待反转区域的第一个节点
    // nxt：永远指向 curr 的下一个节点,循环过程中，curr 变化以后 Cur_next 会变化；
    // pre：永远指向待反转区域的第一个节点 left 的前一个节点,在循环过程中不变。
    //
    // |---------3->|
    // 1      3<-2--5     2     4
    //        |-----1---->|
    // pre    cur   nxt
    for (int i = m; i < n; i++) {
      ListNode *nxt = cur->next;
      cur->next = nxt->next;
      nxt->next = pre->next;
      pre->next = nxt;
    }
    return dummy->next;
  }
};
