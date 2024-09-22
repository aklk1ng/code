#include "ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(int min, int max)
    : m_maxnum(max), m_minnum(min), m_stop(false), m_idleThread(max / 2),
      m_curThread(max / 2) {
    // Create manager thread.
    m_manager = new std::thread(&ThreadPool::manager, this);
    // Create worker threads.
    for (int i = 0; i < max / 2; i++) {
        std::thread t(&ThreadPool::worker, this);
        m_workers.insert(std::make_pair(t.get_id(), std::move(t)));
    }
}

void ThreadPool::addTask(std::function<void(void)> task) {
    {
        std::lock_guard<std::mutex> locker(m_queueMutex);
        m_tasks.emplace(task);
    }
    m_cond.notify_one();
}

void ThreadPool::manager() {
    while (!m_stop.load()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int idle = m_idleThread.load();
        int cur = m_curThread.load();
        if (idle > cur / 2 && cur > m_minnum) {
            m_exitThread.store(2);
            m_cond.notify_all();
            std::lock_guard<std::mutex> lock(m_idsMutex);
            for (auto &id : m_ids) {
                auto it = m_workers.find(id);
                if (it != m_workers.end()) {
                    std::cout << "----- Thread " << (*it).first
                              << " desdroyed..." << '\n';
                    (*it).second.join();
                    m_workers.erase(it);
                }
            }
            m_ids.clear();
        } else if (!idle && cur < m_maxnum) {
            std::thread t(&ThreadPool::worker, this);
            m_workers.insert(std::make_pair(t.get_id(), std::move(t)));
            m_curThread++;
            m_idleThread++;
        }
    }
}

void ThreadPool::worker() {
    while (!m_stop.load()) {
        std::function<void(void)> task = nullptr;
        {
            std::unique_lock<std::mutex> locker(m_queueMutex);
            // Task queue is empty.
            while (m_tasks.empty() && !m_stop.load()) {
                m_cond.wait(locker);
                if (m_exitThread.load() > 0) {
                    m_curThread--;
                    m_idleThread--;
                    m_exitThread--;
                    std::cout << "-----Thread exit, id: "
                              << std::this_thread::get_id() << '\n';
                    std::lock_guard<std::mutex> lock(m_idsMutex);
                    m_ids.emplace_back(std::this_thread::get_id());
                    return;
                }
            }
            // Take task.
            if (!m_tasks.empty()) {
                std::cout << "Take a task..." << '\n';
                task = std::move(m_tasks.front());
                m_tasks.pop();
            }
        }
        // Execute.
        if (task) {
            m_idleThread--;
            task();
            m_idleThread++;
        }
    }
}

ThreadPool::~ThreadPool() {
    m_stop.store(true);
    m_cond.notify_all();
    for (auto &it : m_workers) {
        std::thread &t = it.second;
        if (t.joinable()) {
            std::cout << "***** Thread " << t.get_id() << " exit..." << '\n';
            t.join();
        }
    }
    if (m_manager->joinable()) {
        m_manager->join();
    }
    delete m_manager;
}

void calc(int x, int y) {
    int z = x + y;
    std::cout << "z = " << z << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int cal(int x, int y) {
    int z = x + y;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return z;
}

int main(int argc, char *argv[]) {
    ThreadPool pool;
    std::vector<std::future<int>> res;
    for (int i = 0; i < 10; i++) {
        res.emplace_back(pool.addTask(cal, i, i * 2));
    }

    for (auto &e : res) {
        std::cout << e.get() << '\n';
    }
    return 0;
}
