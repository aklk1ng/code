#include <iostream>
using namespace std;

typedef int ElementType;

class ListNode {
public:
  struct Node {
    ElementType val;
    Node *next;
    Node(ElementType val) : val(val), next(nullptr) {}
    Node(Node *ptr) : val(ptr->val), next(ptr) {}
  };

  ListNode() {
    dummy = new Node(-1);
    size = 0;
  }

  ElementType get(int index) {
    if (index < 0 || index > (size - 1)) {
      return -1;
    }
    Node *cur = dummy->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void ListNodeInsert(int index, ElementType val) {
    if (index < 0 || index > size) {
      return;
    }
    Node *cur = dummy;
    Node *newnode = new Node(val);
    while (index--) {
      cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;

    size++;
  }

  void ListNodeErase(int index) {
    if (index < 0 || index > (size - 1)) {
      return;
    }
    Node *cur = dummy;
    while (index--) {
      cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;

    size--;
  }

  void HeadInsert(ElementType val) {
    Node *newnode = new Node(val);
    Node *head = dummy->next;
    dummy->next = newnode;
    newnode->next = head;

    size++;
  }

  void TailInsert(ElementType val) {
    Node *cur = dummy->next;
    while (cur) {
      cur = cur->next;
    }
    Node *newnode = new Node(val);
    newnode->next = cur->next;
    cur->next = newnode;

    size++;
  }

  void Print() {
    Node *cur = dummy->next;
    while (cur) {
      cout << cur->val << "->";
      cur = cur->next;
    }
    cout << "nullptr" << endl;
  }

private:
  int size;
  Node *dummy;
};

void test() {
  ListNode l;
  l.HeadInsert(1);
  l.ListNodeInsert(0, 0);
  l.ListNodeInsert(1, 1);
  l.ListNodeErase(2);
  l.Print();
  cout << l.get(1) << endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
