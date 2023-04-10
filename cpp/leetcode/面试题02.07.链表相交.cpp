#include <cstdio>
#include <iostream>
#include <type_traits>
#include <utility>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA;
    ListNode *curB = headB;
    int lenA = 0;
    int lenB = 0;
    while (curA) {
      curA = curA->next;
      lenA++;
    }
    while (curB) {
      curB = curB->next;
      lenB++;
    }

    curA = headA;
    curB = headB;
    if (lenB > lenA) {
      swap(lenA, lenB);
      swap(curA, curB);
    }

    int gap = lenA = lenB;
    while (gap--) {
      curA = curA->next;
    }
    while (curA) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return NULL;
  }
};
