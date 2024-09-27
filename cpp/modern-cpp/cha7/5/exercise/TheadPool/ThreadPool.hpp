#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <condition_variable>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

class ThreadPool {
  public:
    // Initialize the number of concurrency threads.
    ThreadPool(size_t);

    // Enqueue new thread task.
    template <class F, class... Args>
    decltype(auto) enqueue(F &&f, Args &&...args);
    // Destroy thread pool and all created threads.
    ~ThreadPool();

  private:
    // Thread list, stores all threads.
    std::vector<std::thread> workers;
    // Queue task, the type of queue elements are function with void return
    // type.
    std::queue<std::function<void()>> tasks;
    // For synchoniztion.
    std::mutex queue_mtx;
    // Used to block a therad or threads at the same time until all of them
    // modified condition_variable.
    std::condition_variable cond;
    bool stop;
};

inline ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for (size_t i = 0; i < threads; i++) {
        workers.emplace_back([this] { // Capture the instance of thread pool.
            while (true) {
                std::function<void()> task;

                {
                    // Get mutex
                    std::unique_lock<std::mutex> lock(this->queue_mtx);
                    // Block current thread
                    this->cond.wait(lock, [this] {
                        return this->stop || !this->tasks.empty();
                    });
                    // Return if queue empty and task finished
                    if (this->stop && this->tasks.empty()) {
                        return;
                    }

                    // Otherwise execute the first task of queue
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }

                task();
            }
        });
    }
}

template <class F, class... Args>
decltype(auto) ThreadPool::enqueue(F &&f, Args &&...args) {
    using return_type = typename std::result_of<F(Args...)>::type;
    // Fetch task
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();

    {
        std::unique_lock<std::mutex> lock(queue_mtx);
        if (stop) {
            throw std::runtime_error("enqueue on stopped TrheadPool");
        }
        tasks.emplace([task] { (*task)(); });
    }

    cond.notify_one();
    return res;
}

inline ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mtx);
        stop = true;
    }

    // Wake up all threads.
    cond.notify_all();
    // Let all processes into synchronous execution
    for (auto &work : workers) {
        work.join();
    }
}


#endif
