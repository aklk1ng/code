#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *pre, *next;
  Node(int _val) : val(_val), pre(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
  Node *head, *tail;
  int size;
  int capacity;

public:
  MyCircularDeque(int k) : head(nullptr), tail(nullptr), size(0), capacity(k) {}

  bool insertFront(int value) {
    if (isFUll())
      return false;

    Node *newnode = new Node(value);
    if (!newnode)
      return false;
    if (size == 0)
      head = tail = newnode;
    else {
      newnode->next = head;
      head->pre = newnode;
      head = newnode;
    }

    size++;
    return true;
  }

  bool insertLast(int value) {
    if (isFUll())
      return false;

    Node *newnode = new Node(value);
    if (!newnode)
      return false;
    if (size == 0)
      head = tail = newnode;
    else {
      newnode->pre = tail;
      tail->next = newnode;
      tail = newnode;
    }

    size++;
    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;

    Node *node = head;
    head = head->next;
    if (head)
      head->pre = nullptr;
    delete node;
    size--;
    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;

    Node *node = tail;
    tail = tail->pre;
    if (tail)
      tail->next = nullptr;
    delete node;
    size--;
    return true;
  }

  int getFront() {
    if (size == 0)
      return -1;
    return head->val;
  }

  int getRead() {
    if (size == 0)
      return -1;
    return tail->val;
  }

  bool isEmpty() { return size == 0; }

  bool isFUll() { return size == capacity; }
};
