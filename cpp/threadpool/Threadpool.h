#pragma once
#include "TaskQueue.cpp"
#include "TaskQueue.h"
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;
template <typename T>
class ThreadPool {
public:
  // 创建线程池并初始化
  ThreadPool(int max, int min);

  // 销毁线程池
  ~ThreadPool();

  // 给线程池添加任务
  void addTask(Task<T> task);

  // 当前线程池的工作的线程数

  int getBusyNum();

  // 线程池中的存活的线程的个数
  int getAliveNum();

private:
  // 任务队列.循环队列
  TaskQueue<T> *taskQ;

  pthread_t managerID;       // 管理者id
  pthread_t *threadIDs;      // 工作的线程id
  int maxnum;                // 最大线程数量
  int minnum;                // 最小线程数量
  int busynum;               // 处于工作的线程
  int livenum;               // 存活的线程
  int destroynum;            // 要销毁的线程
  pthread_mutex_t mutexPool; // 对整个线程池进行加锁
  pthread_cond_t IsEmpty;    // 任务队列是否空了
  static const int NUMBER = 2;

  bool shutdown; // 销毁线程池的标志位，1为销毁，0为不销毁
                 // 工作函数
  static void *worker(void *arg);
  // 管理函数
  static void *manager(void *arg);
  // 线程退出函数
  void ThreadExit();
};
