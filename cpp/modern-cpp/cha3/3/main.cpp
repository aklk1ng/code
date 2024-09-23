#include <iostream>

void ref(std::string &str) { std::cout << "lvalue\n"; }

void ref(std::string &&str) { std::cout << "rvalue\n"; }

class A {
  public:
    int *ptr;

    A() : ptr(new int(1)) { std::cout << "construct " << ptr << '\n'; }

    A(A &a) : ptr(new int(*a.ptr)) { std::cout << "copy " << ptr << '\n'; }

    A(A &&a) : ptr(a.ptr) {
        a.ptr = nullptr;
        std::cout << "move " << ptr << '\n';
    }

    ~A() { std::cout << "destruct " << ptr << '\n'; }
};

A return_rval(bool p) {
    A a, b;
    return p ? a : b;
}

void reference(int &v) { std::cout << "left reference\n"; }

void reference(int &&v) { std::cout << "right reference\n"; }

template <typename T>
void pass(T &&v) {
    std::cout << "pass arguments: ";
    reference(v);
    std::cout << "std::move pass arguments: ";
    reference(std::move(v));
    std::cout << "std::forward pass arguments: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast pass arguments: ";
    reference(static_cast<T&&>(v));
}

int main(int argc, char *argv[]) {
    const char(&left)[6] = "01234";
    const char *p = "01234";
    const char *&&p1 = "01234";
    // const char *&p2 = "01234";
    std::cout << left << '\n';
    static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");

    std::cout << "-------------\n";

    std::string lv1 = "string,";
    std::string &&rv1 = std::move(lv1);
    std::cout << rv1 << '\n';

    const std::string &lv2 = lv1 + lv1;
    std::cout << lv2 << '\n';

    std::string &&rv2 = lv1 + lv2;
    rv2 += "test";
    std::cout << rv2 << '\n';

    ref(rv2);

    std::cout << "-------------\n";

    A obj = return_rval(false);
    std::cout << "obj:\n";
    std::cout << obj.ptr << '\n';
    std::cout << *obj.ptr << '\n';

    std::cout << "-------------\n";

    std::cout << "pass rvalue\n";
    pass(1);
    std::cout << "pass lvalue\n";
    int v = 1;
    pass(v);

    return 0;
}
