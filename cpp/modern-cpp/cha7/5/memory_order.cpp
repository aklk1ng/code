#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void relaxed_model() {
    std::atomic<int> counter = {0};
    std::vector<std::thread> v;

    for (int i = 0; i < 100; i++) {
        v.emplace_back(
            [&]() { counter.fetch_add(1, std::memory_order_relaxed); });
    }
    for (auto &e : v) {
        e.join();
    }
    std::cout << counter << '\n';
}

void release_consumption_model() {
    std::atomic<int *> ptr(nullptr);
    int v;
    std::thread producer([&]() {
        int *p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });
    std::thread consumer([&]() {
        int *p;
        while (!(p = ptr.load(std::memory_order_consume)))
            ;
        std::cout << "p: " << *p << '\n';
        std::cout << "v: " << v << '\n';
    });
    producer.join();
    consumer.join();
}

void release_acquire_model() {
    std::vector<int> v;
    std::atomic<int> flag = {0};
    std::thread release([&]() {
        v.push_back(42);
        flag.store(1, std::memory_order_release);
    });
    std::thread acqrel([&]() {
        int expected = 1;
        while (!flag.compare_exchange_strong(expected, 2,
                                             std::memory_order_acq_rel)) {
            expected = 1;
        }
    });
    std::thread acquire([&]() {
        int expected = 1;
        while (flag.load(std::memory_order_acquire) < 2)
            ;
        std::cout << v.at(0) << '\n';
    });
    release.join();
    acqrel.join();
    acquire.join();
}

void sequential_model() {
    std::atomic<int> counter = {0};
    std::vector<std::thread> v;
    for (int i = 0; i < 100; i++) {
        v.emplace_back(
            [&]() { counter.fetch_add(1, std::memory_order_seq_cst); });
    }
    for (auto &e : v) {
        e.join();
    }
    std::cout << counter << '\n';
}

int main(int argc, char *argv[]) {
    relaxed_model();
    release_consumption_model();
    release_acquire_model();
    sequential_model();
    return 0;
}
