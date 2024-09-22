#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);

int main(int argc, char *argv[]) {
    if (std::is_same<decltype(NULL), decltype(0)>::value) {
        std::cout << "NULL == 0\n";
    }
    if (std::is_same<decltype(NULL), decltype((void *)0)>::value) {
        std::cout << "NULL == 0\n";
    }
    if (std::is_same<decltype(NULL), std::nullptr_t>::value) {
        std::cout << "NULL == 0\n";
    }

    const int len = 4;
    char a[len] = {'a', 'b', 'c', 'd'};
    for (int i = 0; i < len; i++) {
        std::cout << a[i] << " \n"[i == len - 1];
    }
    foo(0);
    foo(nullptr);
    return 0;
}

void foo(char *) { std::cout << "foo(char *) is called\n"; }

void foo(int i) { std::cout << "foo(int) is called\n"; }
