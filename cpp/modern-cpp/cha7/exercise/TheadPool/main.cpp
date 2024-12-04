#include "ThreadPool.hpp"
#include <iostream>
#include <string>
#include <thread>

int main() {
    ThreadPool pool(4);
    std::vector<std::future<std::string>> res;

    for (int i = 0; i < 8; i++) {
        res.emplace_back(pool.enqueue([i] {
            std::cout << "Hello " << i << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "World " << i << '\n';
            return std::string("---Thread ") + std::to_string(i) +
                   std::string(" finished.---");
        }));
    }

    for (auto &&e : res) {
        std::cout << e.get() << ' ';
    }
    std::cout << '\n';
}
