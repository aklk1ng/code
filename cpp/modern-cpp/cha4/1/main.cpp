#include <array>
#include <iostream>

void foo(int *p, int len) { return; }

int main(int argc, char *argv[]) {
    std::array<int, 4> a = {1, 2, 3, 4};
    std::cout << a.size() << '\n';
    // foo(a, a.size());
    foo(&a[0], a.size());
    foo(a.data(), a.size());
    return 0;
}
