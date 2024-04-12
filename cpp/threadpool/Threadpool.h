#pragma once
#include "TaskQueue.cpp"
#include "TaskQueue.h"
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;

namespace yazi {
template <typename T>
class ThreadPool {
public:
  ThreadPool(int max, int min);

  ~ThreadPool();

  void addTask(Task<T> task);

  int getBusyNum();

  int getAliveNum();

private:
  TaskQueue<T> *taskQ;

  pthread_t managerID;       // manager id
  pthread_t *threadIDs;      // work thread id
  int maxnum;                // max number of thread
  int minnum;                // min numebr of thred
  int busynum;               // the number of thread that is working
  int livenum;               // the number of thread that is alive
  int destroynum;            // the number of thread that need destory
  pthread_mutex_t mutexPool; // lock about the whole thread pool
  pthread_cond_t IsEmpty;
  static const int NUMBER = 2;

  bool shutdown;
  static void *worker(void *arg);
  static void *manager(void *arg);
  void ThreadExit();
};
} // namespace yazi
