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
    this->dummy = new Node(-1);
    this->size = 0;
    this->Min_Index = 0;
    this->Max_Index = 0;
  }

  ElementType get(int index) {
    if (index < 0 || index > (this->size - 1)) {
      return -1;
    }
    Node *cur = this->dummy->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  ElementType Get_Max() {
    Parse_Most_Value();
    Node *cur = this->dummy->next;
    while (this->Max_Index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  ElementType Get_Min() {
    Parse_Most_Value();
    Node *cur = this->dummy->next;
    while (this->Min_Index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void ListNodeInsert(int index, ElementType val) {
    if (index < 0 || index > this->size) {
      return;
    }
    Node *cur = this->dummy;
    Node *newnode = new Node(val);
    while (index--) {
      cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;

    this->size++;
  }

  void ListNodeErase(int index) {
    if (index < 0 || index > (this->size - 1)) {
      return;
    }
    Node *cur = this->dummy;
    while (index--) {
      cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;

    this->size--;
  }

  void HeadInsert(ElementType val) {
    Node *newnode = new Node(val);
    Node *head = this->dummy->next;
    this->dummy->next = newnode;
    newnode->next = head;

    this->size++;
  }

  void TailInsert(ElementType val) {
    Node *cur = this->dummy->next;
    while (cur) {
      cur = cur->next;
    }
    Node *newnode = new Node(val);
    newnode->next = cur->next;
    cur->next = newnode;

    this->size++;
  }

  void Print() {
    Node *cur = this->dummy->next;
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
    Node *cur = this->dummy->next;
    for (int i = 0; i < this->size; i++) {
      this->Max_Index = max(Max_Index, cur->val);
      this->Min_Index = min(Min_Index, cur->val);
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
