#include <future>
#include <iostream>
#include <thread>
#include <utility>

int main(int argc, char *argv[]) {
    std::packaged_task<int()> task([]() { return 7; });
    std::future<int> res = task.get_future();
    std::thread(std::move(task)).detach();
    std::cout << "waiting...\n";
    res.wait();
    std::cout << "done!\n" << "future result is " << res.get() << '\n';
    return 0;
}
