#include <iostream>

typedef int ElementType;

class Queue {
public:
  struct Node {
    ElementType val;
    Node *next;

    Node(ElementType val) : val(val), next(nullptr) {}
  };

  struct QueuePtr {
    Node *head;
    Node *tail;

    QueuePtr() : head(nullptr), tail(nullptr) {}
  };

  Queue() { ps = new QueuePtr(); }

  ~Queue() {
    Node *cur = ps->head;
    while (cur) {
      Node *next = cur->next;
      delete cur;
      cur = next;
    }
    ps->head = nullptr;
    ps->tail = nullptr;
  }

  void QueuePush(ElementType x) {
    Node *newnode = new Node(x);
    newnode->val = x;
    newnode->next = nullptr;
    if (ps->head == nullptr) {
      ps->head = ps->tail = newnode;
    } else {
      ps->tail->next = newnode;
      ps->tail = newnode;
    }
    this->size++;
  }

  void QueuePop() {
    Node *cur = ps->head->next;
    delete ps->head;
    ps->head = cur;
    if (ps->head == nullptr) {
      ps->tail = nullptr;
    }
    this->size--;
  }

  void Print() {
    Node *cur = ps->head;
    while (cur) {
      std::cout << cur->val << "<-";
      cur = cur->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  ElementType QueueFront() { return ps->head->val; }

  ElementType QueueTail() { return ps->tail->val; }

  int QueueGetSize() { return this->size; }

private:
  int size;
  QueuePtr *ps;
};

void test() {
  Queue q;
  q.QueuePush(0);
  q.QueuePush(1);
  q.QueuePush(2);
  q.QueuePop();
  q.Print();
  std::cout << "-----------------" << std::endl;
  std::cout << q.QueueGetSize() << std::endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
