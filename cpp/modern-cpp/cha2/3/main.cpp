#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y) {
    return x + y;
}

template <typename T, typename U>
auto add2(T x, U y) {
    return x + y;
}

int main(int argc, char *argv[]) {
    auto [x, y, z] = f();
    std::cout << x << ' ' << y << ' ' << z << '\n';

    if (std::is_same<decltype(x), int>::value) {
        std::cout << "type x == int\n";
    }
    if (std::is_same<decltype(x), float>::value) {
        std::cout << "type y == float\n";
    }
    if (std::is_same<decltype(x), decltype(z)>::value) {
        std::cout << "type x == type z\n";
    }

    auto w = add<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "type w == double\n";
    }
    std::cout << w << '\n';
    auto q = add2<double, int>(2.0, 1);
    std::cout << q << '\n';
}
