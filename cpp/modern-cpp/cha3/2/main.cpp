#include <functional>
#include <iostream>
using foo = void(int);

void function(foo f) { f(1); }

int bar(int val) { return val; };

void Foo(int a, int b, int c) {
    std::cout << a << ' ' << b << ' ' << c << '\n';
}

int main(int argc, char *argv[]) {
    auto f = [](int val) { std::cout << val << '\n'; };
    function(f); // Closure object(convert to `foo*` function pointer)
    f(1);        // Lambda expression call

    std::cout << "------------\n";

    std::function<int(int)> func = bar;
    int important = 10;
    std::function<int(int)> func2 = [&](int val) -> int {
        return val * important;
    };
    std::cout << func(10) << '\n';
    std::cout << func2(10) << '\n';

    std::cout << "------------\n";

    auto obj = std::bind(Foo, std::placeholders::_1, 1, 2);
    obj(1);
    return 0;
}
