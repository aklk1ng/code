#include <atomic>
#include <iostream>
#include <thread>

class mutex {
    std::atomic<bool> flag{false};

  public:
    void lock() {
        while (flag.exchange(true, std::memory_order_relaxed))
            ;
        std::atomic_thread_fence(std::memory_order_acquire);
    }

    void unlock() {
        std::atomic_thread_fence(std::memory_order_release);
        flag.store(false, std::memory_order_relaxed);
    }
};

int a = 0;

int main() {
    mutex mt;
    std::thread t1([&]() {
        mt.lock();
        a += 1;
        mt.unlock();
    });
    std::thread t2([&]() {
        mt.lock();
        a += 2;
        mt.unlock();
    });
    t1.join();
    t2.join();
    std::cout << a << '\n';
    return 0;
}
