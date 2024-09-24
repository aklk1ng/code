#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) { (*i)++; }

int main(int argc, char *argv[]) {
    auto ptr = std::make_shared<int>(10);
    foo(ptr);
    std::cout << *ptr << '\n';
    auto ptr2 = ptr;
    auto ptr3 = ptr;
    int *p = ptr.get();
    std::cout << ptr.use_count() << '\n';
    std::cout << ptr2.use_count() << '\n';
    std::cout << ptr3.use_count() << '\n';

    ptr2.reset();
    std::cout << ptr.use_count() << '\n';
    std::cout << ptr2.use_count() << '\n';
    std::cout << ptr3.use_count() << '\n';

    ptr3.reset();
    std::cout << ptr.use_count() << '\n';
    std::cout << ptr2.use_count() << '\n';
    std::cout << ptr3.use_count() << '\n';
    return 0;
}
