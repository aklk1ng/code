#include <iostream>
#include <vector>
#include <initializer_list>

class Foo {
  public:
    std::vector<int> v;

    Foo(std::initializer_list<int> list) {
        for (auto &it : list) {
            v.push_back(it);
        }
    }
};

int main(int argc, char *argv[]) {
    Foo foo = {1, 2, 3, 4, 5};
    Foo foo2{3, 4};
    for (auto &e : foo.v) {
        std::cout << e << '\n';
    }
    return 0;
}
