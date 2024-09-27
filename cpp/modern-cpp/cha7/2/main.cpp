#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void foo(int var) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);
    v = var;
}

void bar(int var) {
    static std::mutex mt;
    std::unique_lock<std::mutex> lock(mt);
    v = var;
    std::cout << v << '\n';
    lock.unlock();

    lock.lock();
    v += 1;
    std::cout << v << '\n';
}

int main(int argc, char *argv[]) {
    std::thread t1(foo, 2), t2(foo, 3);
    t1.join();
    t2.join();
    std::cout << v << '\n';

    std::thread t3(bar, 4), t4(bar, 5);
    t3.join();
    t4.join();
    return 0;
}
