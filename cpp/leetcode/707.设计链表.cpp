#include <iostream>
using namespace std;

class MyLinkedList {
public:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
  };

  MyLinkedList() {
    dummy = new ListNode(-1);
    size = 0;
  }

  int get(int index) {
    if (index < 0 || index > (size - 1)) {
      return -1;
    }
    ListNode *cur = dummy->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    ListNode *newnode = new ListNode(val);
    newnode->next = dummy->next;
    dummy->next = newnode;
    size++;
  }

  void addAtTail(int val) {
    ListNode *cur = dummy;
    while (cur->next) {
      cur = cur->next;
    }
    ListNode *newnode = new ListNode(val);
    cur->next = newnode;
    size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }
    ListNode *cur = dummy;
    while (index--) {
      cur = cur->next;
    }
    ListNode *newnode = new ListNode(val);
    newnode->next = cur->next;
    cur->next = newnode;
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index > (size - 1)) {
      return;
    }
    ListNode *cur = dummy;
    while (index--) {
      cur = cur->next;
    }
    ListNode *tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    size--;
  }

private:
  ListNode *dummy;
  int size;
};
