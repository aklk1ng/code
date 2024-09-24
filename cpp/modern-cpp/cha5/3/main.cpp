#include <iostream>
#include <memory>

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
    Foo() { std::cout << "Foo::Foo\n"; }

    ~Foo() { std::cout << "~Foo::Foo\n"; }

    void foo() { std::cout << "Foo::foo\n"; }
};

void f(const Foo &) { std::cout << "f(const foo &)\n"; }

int main(int argc, char *argv[]) {
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    if (p1) {
        p1->foo();
    }
    {
        std::unique_ptr<Foo> p2(std::move(p1));
        f(*p2);
        if (p2) {
            p2->foo();
        }
        if (p1) {
            p1->foo();
        }
        if (p2) {
            p2->foo();
        }
        std::cout << "p2 destroyed\n";
    }
    if (p1) {
        p1->foo();
    }

    return 0;
}
