#include <iostream>
#include <memory>
#include <utility>

void f1() {
    int val = 1;
    // Copy the val.
    auto copy_val = [val] { return val; };
    val = 100;
    auto stored_val = copy_val();
    std::cout << stored_val << '\n';
    std::cout << val << '\n';
}

void f2() {
    int val = 1;
    auto copy_val = [&val] { return val; };
    val = 100;
    auto stored_val = copy_val();
    std::cout << stored_val << '\n';
    std::cout << val << '\n';
}

void f4() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << '\n';
}

int main(int argc, char *argv[]) {
    f1();
    std::cout << "----------\n";
    f2();
    std::cout << "----------\n";
    f4();
    return 0;
}
