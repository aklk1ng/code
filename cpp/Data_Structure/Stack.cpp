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
    StackList(ElementType x) : v(x) {}
  };

  Stack(ElementType x) { s = new StackList(x); }
  ~Stack() { s->v.clear(); }

  void StackPush(ElementType x) { s->v.push_back(x); }

  void StackPop() { s->v.pop_back(); }

  int StackSize() { return s->v.size(); }

  void Print() {
    auto it = s->v.begin();
    for (; it != s->v.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl;
  }

  ElementType Get_Pos(int index) { return s->v.at(index); }

  ElementType Top() { return s->v.back(); }

private:
  StackList *s;
};

void test() {
  Stack s(0);
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
  cout << s.Top() << endl;
  cout << s.StackSize() << endl;
  cout << s.Get_Pos(5) << endl;
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
