#include <algorithm>
#include <iostream>
using namespace std;

typedef int ElementType;

class Double_ListNode {
public:
  struct Node {
    ElementType val;
    Node *next;
    Node *pre;
    Node(ElementType x) : val(x), next(nullptr), pre(nullptr) {}
  };

  Double_ListNode(ElementType x) {
    head = new Node(x);
    head->next = head;
    head->pre = head;
    size = 1;
    Max_Index = 0;
    Min_Index = 0;
  }
  ~Double_ListNode() {
    Node *cur = head;
    for (int i = 0; i < size; i++) {
      Node *next = cur->next;
      delete cur;
      cur = next;
    }
  }

  void Insert_Pos(int index, ElementType x) {
    if (index < 0 || index > size) {
      cout << "error index" << endl;
      return;
    }
    Node *cur = head;
    Node *newnode = new Node(x);

    if (index == 0) {
      newnode->next = head;
      head->pre = newnode;
      newnode->pre = head;
      head->next = newnode;
      head = newnode;
    } else {
      while (index--) {
        cur = cur->next;
      }
      Node *pre = cur->pre;
      pre->next = newnode;
      newnode->pre = pre;
      newnode->next = cur;
      cur->pre = newnode;
    }
    size++;
  }

  void Erase_Pos(int index) {
    if (index < 0 || index > (size - 1)) {
      return;
    } else if (index == 0) {
      Node *cur = head;
      Node *last = head->pre;
      Node *next = head->next;
      next->pre = last;
      last->next = next;
      delete cur;
      head = next;
    } else if (index == (size - 1)) {
      Node *cur = head->pre;
      Node *last = cur->pre;
      last->next = head;
      head->pre = last;
      delete cur;
    }
    size--;
  }

  void Insert_Head(ElementType x) { Insert_Pos(0, x); }

  void Inset_Tail(ElementType x) { Insert_Pos(size, x); }

  void Erase_Head() { Erase_Pos(0); }

  void Erase_Tail() { Erase_Pos(size - 1); }

  void Print() {
    Node *cur = head;
    for (int i = 0; i < size; i++) {
      cout << cur->val << "->";
      cur = cur->next;
    }
    cout << "nullptr" << endl;
  }

  ElementType Get(int index) {
    if (index < 0 || index > (size - 1)) {
      return -1;
    }
    Node *cur = head;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  ElementType Get_Max() {
    Parse_Most_Value();
    Node *cur = head;
    while (Max_Index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  ElementType Get_Min() {
    Parse_Most_Value();
    Node *cur = head;
    while (Min_Index--) {
      cur = cur->next;
    }
    return cur->val;
  }

private:
  Node *head;
  int size;
  int Max_Index;
  int Min_Index;

  void Parse_Most_Value() {
    Node *cur = head;
    for (int i = 0; i < size; i++) {
      Max_Index = max(Max_Index, cur->val);
      Min_Index = min(Min_Index, cur->val);
      cur = cur->next;
    }
  }
};

void test() {
  Double_ListNode n(0);
  n.Insert_Head(0);
  n.Inset_Tail(2);
  n.Insert_Pos(2, 3);
  n.Print();
  n.Erase_Head();
  n.Print();
  n.Erase_Tail();
  n.Print();
  n.Erase_Pos(1);
  n.Print();
  cout << n.Get(2) << endl;
  cout << n.Get_Max() << endl;
  n.Inset_Tail(1);
  n.Print();
  cout << n.Get_Max() << endl;
  cout << n.Get_Min() << endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
