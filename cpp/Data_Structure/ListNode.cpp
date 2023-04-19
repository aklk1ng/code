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
    Min_Index = 0;
    Max_Index = 0;
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

  ElementType Get_Max() {
    Parse_Most_Value();
    Node *cur = dummy->next;
    while (Max_Index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  ElementType Get_Min() {
    Parse_Most_Value();
    Node *cur = dummy->next;
    while (Min_Index--) {
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
  int Max_Index;
  int Min_Index;

  void Parse_Most_Value() {
    Node *cur = dummy->next;
    for (int i = 0; i < size; i++) {
      Max_Index = max(Max_Index, cur->val);
      Min_Index = min(Min_Index, cur->val);
      cur = cur->next;
    }
  }
};

void test() {
  ListNode l;
  l.HeadInsert(1);
  l.ListNodeInsert(0, 0);
  l.ListNodeInsert(1, 1);
  l.ListNodeErase(2);
  l.Print();
  cout << l.get(1) << endl;
  cout << l.Get_Max() << endl;
  cout << l.Get_Min() << endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
