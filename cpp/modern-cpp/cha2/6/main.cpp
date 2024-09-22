#include <iostream>

class Base {
  public:
    int val1, val2;

    Base() { val1 = 1; }

    Base(int val) : Base() { val2 = val; }
};

class Subclass : public Base {
  public:
    using Base::Base;
};

class Magic {
  public:
    Magic() = default;
    Magic &operator=(const Magic &) = delete;
    Magic(int num);
};

enum class new_enum : unsigned int {
    val1,
    val2,
    val3 = 100,
    val4 = 100
};

template <typename T>
std::ostream &operator<<(
    typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream,
    const T &e) {
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main(int argc, char *argv[]) {
    Base b(2);
    std::cout << b.val1 << ' ' << b.val2 << '\n';
    Subclass s(3);
    std::cout << s.val1 << ' ' << s.val2 << '\n';
    if (new_enum::val3 == new_enum::val4) {
        std::cout << "equal\n";
    }
    std::cout << new_enum::val3 << '\n';
    return 0;
}
