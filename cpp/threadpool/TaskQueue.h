#pragma once
#include <cstddef>
#include <pthread.h>
#include <queue>
using callback = void (*)(void *arg);

namespace yazi {
template <typename T>
struct Task {
  Task() {
    function = nullptr;
    arg = nullptr;
  }

  Task(callback f, void *arg) {
    this->arg = (T *)arg;
    function = f;
  }

  callback function;
  T *arg;
};

template <typename T>
class TaskQueue {
public:
  TaskQueue();
  ~TaskQueue();

  void addTask(Task<T> task);
  void addTask(callback f, void *arg);

  Task<T> takeTask();

  inline size_t taskNumber() { return taskQ.size(); }

private:
  pthread_mutex_t mutex;
  std::queue<Task<T>> taskQ;
};
} // namespace yazi
