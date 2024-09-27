#include <atomic>
#include <iostream>
#include <thread>

void foo() {
    int a = 0;
    volatile int flag = 0;

    std::thread t1([&]() {
        while (flag != 1) {
            int b = a;
            std::cout << "b = " << b << '\n';
        }
    });

    std::thread t2([&]() {
        a = 5;
        flag = 1;
    });

    t1.join();
    t2.join();
}

std::atomic<int> count = {0};

void bar() {
    std::thread t1([]() { count.fetch_add(1); });
    std::thread t2([]() {
        count++;
        count += 1;
    });
    t1.join();
    t2.join();
    std::cout << count << '\n';
}

struct A {
    float x;
    int y;
    long long z;
};

int main(int argc, char *argv[]) {
    foo();
    bar();

    std::atomic<A> a;
    std::cout << std::boolalpha << a.is_lock_free() << '\n'; // Can't compile
    return 0;
}
