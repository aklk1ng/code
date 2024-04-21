#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#if 1
// hungry man mode --> create a singleton object when defining a class
class TaskQueue {
public:
  TaskQueue(const TaskQueue &t) = delete;
  TaskQueue &operator=(const TaskQueue &t) = delete;
  static TaskQueue *getInstance() { return m_taskQ; }
  void print() { std::cout << "I am a member function..." << std::endl; }

  bool isEmpty() {
    std::lock_guard<std::mutex> locker(m_mutex);
    bool flag = m_data.empty();
    return flag;
  }

  void addTask(int node) {
    std::lock_guard<std::mutex> locker(m_mutex);
    m_data.push(node);
  }

  bool popTask() {
    std::lock_guard<std::mutex> locker(m_mutex);
    if (m_data.empty()) {
      return false;
    }
    m_data.pop();
    return true;
  }

  int takeTask() {
    std::lock_guard<std::mutex> locker(m_mutex);
    if (m_data.empty()) {
      return -1;
    }
    int data = m_data.front();
    return data;
  }

private:
  TaskQueue() = default;
  /* TaskQueue(const TaskQueue &t) = default; */
  /* TaskQueue &operator=(const TaskQueue &t) = default; */
  static TaskQueue *m_taskQ;
  std::queue<int> m_data;
  std::mutex m_mutex;
};
TaskQueue *TaskQueue::m_taskQ = new TaskQueue;
#endif // 1

#if 0
// lazy mode --> create a corresponding instance when using a singleton object
class TaskQueue {
public:
  TaskQueue(const TaskQueue &t) = delete;
  TaskQueue &operator=(const TaskQueue &t) = delete;
  static TaskQueue *getInstance() {
    TaskQueue *task = m_taskQ.load();
    if (task == nullptr) {
      m_mutex.lock();
      task = m_taskQ.load();
      if (task == nullptr) {
        task = new TaskQueue;
        m_taskQ.store(task);
      }
      m_mutex.unlock();
    }
    return task;
  }
  void print() {
    cout << "I am a member function..." << endl;
  }
private:
  TaskQueue() = default;
  /* TaskQueue(const TaskQueue &t) = default; */
  /* TaskQueue &operator=(const TaskQueue &t) = default; */
  /* static TaskQueue *m_taskQ; */
  static mutex m_mutex;
  static atomic<TaskQueue*> m_taskQ;
};
/* TaskQueue* TaskQueue::m_taskQ = nullptr; */
atomic<TaskQueue*> TaskQueue::m_taskQ;
mutex TaskQueue::m_mutex;
#endif // 0

int main(int argc, char *argv[]) {
  TaskQueue *taskQ = TaskQueue::getInstance();
  std::thread t1([=]() {
    for (int i = 0; i < 10; i++) {
      taskQ->addTask(i);
      std::cout << "push data ++ " << i << "," << std::this_thread::get_id() << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  });

  std::thread t2([=]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    while (!taskQ->isEmpty()) {
      int num = taskQ->takeTask();
      std::cout << "take data -- " << num << "," << std::this_thread::get_id() << std::endl;
      taskQ->popTask();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  });

  t1.join();
  t2.join();
  return 0;
}
