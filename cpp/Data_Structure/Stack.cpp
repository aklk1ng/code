#include <iostream>
#include <ostream>
#include <vector>

typedef int ElementType;
class Stack {
public:
  struct StackList {
    std::vector<ElementType> v;
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
      std::cout << *it << ' ';
    }
    std::cout << std::endl;
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
  std::cout << "---------------" << std::endl;
  std::cout << s.Top() << std::endl;
  std::cout << s.StackSize() << std::endl;
  std::cout << s.Get_Pos(5) << std::endl;
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
