#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

typedef int ElementType;
class Stack {
public:
  struct StackList {
    vector<ElementType> v;
    int size;
    StackList() : v(-1) {}
  };

  Stack() { s = new StackList(); }
  ~Stack() { s->v.clear(); }

  void StackPush(ElementType x) {
    s->v.push_back(x);
    s->size++;
  }

  void StackPop() {
    s->v.pop_back();
    s->size--;
  }

  int StackSize() { return s->size; }

  ElementType StackTop() { return *(s->v.end()); }

  void Print() {
    auto it = s->v.begin();
    for (; it != s->v.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl;
  }

private:
  StackList *s;
};

void test() {
  Stack s;
  s.StackPush(0);
  s.StackPush(1);
  s.StackPush(2);
  s.StackPush(3);
  s.StackPush(4);
  s.StackPush(5);
  s.StackPush(6);
  s.StackPop();
  s.Print();
  cout << "---------------" << endl;
  cout << s.StackTop() << endl;
  cout << s.StackSize() << endl;
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
