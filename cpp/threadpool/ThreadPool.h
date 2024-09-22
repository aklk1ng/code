#pragma once
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <queue>
#include <future>
#include <map>
#include <atomic>
#include <memory>
#include <functional>

class ThreadPool {
  public:
    ThreadPool(int mi = 1, int mx = std::thread::hardware_concurrency());
    ~ThreadPool();

    void addTask(std::function<void(void)> task); // Add task to task queue.

    // Add task to task queue asynchronously.
    template <typename F, typename... Args>
    auto addTask(F &&f, Args &&...args)
        -> std::future<typename std::result_of<F(Args...)>::type> {
        using returnType = typename std::result_of<F(Args...)>::type;
        // Create package_task.
        auto mytask = std::make_shared<std::packaged_task<returnType()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        // Get future.
        auto res = mytask->get_future();
        // Add task.
        m_queueMutex.lock();
        m_tasks.emplace([mytask]() { (*mytask)(); });
        m_queueMutex.unlock();

        m_cond.notify_one();
        return res;
    }

  private:
    std::thread *m_manager;             // Manager thread.
    std::vector<std::thread::id> m_ids; // Exited threads's id.
    std::map<std::thread::id, std::thread>
        m_workers;                 // Map thread's id and thread.
    std::atomic<int> m_minnum;     // The min numver of worker thread.
    std::atomic<int> m_maxnum;     // The max number of worker thread.
    std::atomic<int> m_curThread;  // Current thread.
    std::atomic<int> m_idleThread; // Idle threads.
    std::atomic<int> m_exitThread; // Exit threads.
    std::atomic<bool> m_stop; // Bool variable control whether open ThreadPool.
    std::queue<std::function<void(void)>> m_tasks; // Task queue.
    std::mutex m_queueMutex;                       // Mutex for task queue.
    std::mutex m_idsMutex;                         // Mutex for m_ids.
    std::condition_variable m_cond; // Condition variable for worker threads.

    void manager(); // Manager task function.
    void worker();  // Worker task function.
};
