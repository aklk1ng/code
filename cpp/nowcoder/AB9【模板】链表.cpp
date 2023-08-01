#include <bits/stdc++.h>

using namespace std;

class MyList {
public:
  struct Node {
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
  };

  MyList() {
    dummy = new Node(-1);
    size = 0;
  }

  void Insert(int x, int y) {
    Node *newnode = new Node(y);
    Node *cur = dummy;
    while (cur->next) {
      if (cur->next->val == y) {
        newnode->next = cur->next;
        cur->next = newnode;
        size++;
        return;
      }
    }
    cur->next = newnode;
    size++;
  }

  void Delete(int val) {
    Node *cur = dummy;
    while (cur->next) {
      if (cur->next->val == val) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        size--;
        return;
      }
    }
  }

  void print() {
    Node *cur = dummy->next;
    if (size == 0)
      cout << "NULL" << endl;
    else {
      while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
      }
      cout << endl;
    }
  }

private:
  Node *dummy;
  int size;
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  MyList *list = new MyList();
  string op;
  for (int i = 0; i < n; i++) {
    if (op == "insert") {
      int x, y;
      cin >> x >> y;
      list->Insert(x, y);
    } else if (op == "delete") {
      int val;
      cin >> val;
      list->Delete(val);
    }
  }
  list->print();
  return 0;
}
