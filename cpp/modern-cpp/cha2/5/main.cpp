#include <initializer_list>
#include <iostream>

template <typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << '\n';
}

template <typename... Args>
void printf(const std::string &str, Args... args);

template <typename T>
void printf1(T value) {
    std::cout << value << '\n';
};

template <typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << '\n';
    printf1(args...);
}

// C++17 `printf`.
template <typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << '\n';
    if constexpr (sizeof...(t) > 0) {
        printf2(t...);
    }
}

template <typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << '\n';
    (void)std::initializer_list<T>{
        ([&args] { std::cout << args << '\n'; }(), value)...};
}

// Fold expression
template <typename... T>
auto sum(T... t) {
    return (t + ...);
}

template <typename T, typename U>
auto add(T t, U u) {
    return t + u;
}

template <typename T, int bufsz>
class buffer_t {
  public:
    T &alloc();
    void free(T &t);

  private:
    T data[bufsz];
};

template <auto value> void foo() {
    std::cout << value << '\n';
    return;
}

int main(int argc, char *argv[]) {
    magic();
    magic(1);
    magic(1, "");
    std::cout << "-----------------\n";
    printf1(1, 2, "123", 1.1);
    buffer_t<int, 100> buf;
    foo<10>();
    return 0;
}
