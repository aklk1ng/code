#include "Threadpool.h"
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;

template <typename T>
yazi::ThreadPool<T>::ThreadPool(int max, int min) {
  // 实例化任务队列
  do {
    taskQ = new TaskQueue<T>;
    if (taskQ == nullptr) {
      cout << "new failed!" << endl;
      break;
    }
    threadIDs = new pthread_t[max];
    if (threadIDs == nullptr) {
      cout << "new failed!" << endl;
      break;
    }
    memset(threadIDs, 0, sizeof(pthread_t) * max);
    maxnum = max;
    minnum = min;
    busynum = 0;
    livenum = min; // 与最小的线程相等
    destroynum = 0;

    if (pthread_mutex_init(&mutexPool, NULL) != 0 || pthread_cond_init(&IsEmpty, NULL) != 0) {
      cout << "mutex or conditon int faield!" << endl;
      break;
    }

    shutdown = false;

    // 创建线程
    pthread_create(&managerID, NULL, manager, this);
    for (int i = 0; i < min; i++) {
      pthread_create(&threadIDs[i], NULL, worker, this);
    }
    return;
  } while (0);

  // 释放资源
  if (threadIDs) {
    delete[] (threadIDs);
  }
  if (taskQ) {
    delete[] (taskQ);
  }
}

template <typename T>
yazi::ThreadPool<T>::~ThreadPool() {
  // 关闭线程池
  shutdown = true;
  // 阻塞回收管理线程
  pthread_join(managerID, NULL);
  // 唤醒阻塞的消费者线程
  for (int i = 0; i < livenum; i++) {
    pthread_cond_signal(&IsEmpty);
  }
  // 释放堆内存
  if (taskQ) {
    delete taskQ;
  }
  if (threadIDs) {
    delete threadIDs;
  }
  pthread_mutex_destroy(&mutexPool);
  pthread_cond_destroy(&IsEmpty);
}

template <typename T>
void *yazi::ThreadPool<T>::worker(void *arg) {
  ThreadPool *pool = static_cast<ThreadPool *>(arg);
  while (1) {
    pthread_mutex_lock(&pool->mutexPool);
    // 当前任务队列是否为空
    while (pool->taskQ->taskNumber() == 0 && !pool->shutdown) {
      // 阻塞工作线程
      pthread_cond_wait(&pool->IsEmpty, &pool->mutexPool);

      // 判断是否要销毁线程
      if (pool->destroynum > 0) {
        pool->destroynum--;
        if (pool->livenum < pool->minnum) {
          pool->livenum--;
          pthread_mutex_unlock(&pool->mutexPool);
          pool->ThreadExit();
        }
      }
    }

    // 判断线程池u是否被关闭
    if (pool->shutdown) {
      pthread_mutex_unlock(&pool->mutexPool);
      pool->ThreadExit();
    }

    // 从任务队列中取出一个任务
    Task<T> task = pool->taskQ->takeTask();
    // 解锁
    pool->busynum++;
    pthread_mutex_unlock(&pool->mutexPool);

    cout << "thread " << to_string(pthread_self()) << " begin working" << endl;
    task.function(task.arg);
    delete task.arg;
    task.arg = nullptr;

    cout << "thread " << to_string(pthread_self()) << " end working" << endl;
    pthread_mutex_lock(&pool->mutexPool);
    pool->busynum--;
    pthread_mutex_unlock(&pool->mutexPool);
  }
  return NULL;
}

template <typename T>
void *yazi::ThreadPool<T>::manager(void *arg) {
  ThreadPool *pool = static_cast<ThreadPool *>(arg);
  while (!pool->shutdown) {
    // 每隔3s检测一次
    sleep(3);

    // 取出线程中任务的数量和当前线程的数量
    pthread_mutex_lock(&pool->mutexPool);
    int queueSize = pool->taskQ->taskNumber();
    int livenum = pool->livenum;
    // 取出忙的线程的数量
    int busynum = pool->busynum;
    pthread_mutex_unlock(&pool->mutexPool);

    // 添加线程--任务的个数>存活的个数&&存活的线程数<最大线程数
    if (queueSize > livenum && livenum < pool->maxnum) {
      pthread_mutex_lock(&pool->mutexPool);
      int counter = 0;
      for (int i = 0; i < pool->maxnum && counter <= NUMBER && pool->livenum <= pool->maxnum; i++) {
        if (pool->threadIDs[i] == 0) {
          pthread_create(&pool->threadIDs[i], NULL, worker, NULL);
          counter++;
          pool->livenum++;
        }
      }
      pthread_mutex_unlock(&pool->mutexPool);
    }

    // 销毁线程--忙的线程*2 < 存活的线程数 && 存活的线程数 < 最小线程数
    if (busynum * 2 < livenum && livenum > pool->minnum) {
      pthread_mutex_lock(&pool->mutexPool);
      pool->destroynum = NUMBER;
      pthread_mutex_unlock(&pool->mutexPool);

      // 让工作的线程自杀
      for (int i = 0; i < NUMBER; i++) {
        // 对空闲的线程进行唤醒
        pthread_cond_signal(&pool->IsEmpty);
      }
    }
  }
  return NULL;
}

template <typename T>
void yazi::ThreadPool<T>::addTask(Task<T> task) {
  if (shutdown) {
    return;
  }
  // 添加任务
  taskQ->addTask(task);
  pthread_cond_signal(&IsEmpty);
}

template <typename T>
int yazi::ThreadPool<T>::getBusyNum() {
  pthread_mutex_lock(&mutexPool);
  int busynum = this->busynum;
  pthread_mutex_unlock(&mutexPool);
  return busynum;
}

template <typename T>
int yazi::ThreadPool<T>::getAliveNum() {
  pthread_mutex_lock(&mutexPool);
  int alivenum = this->livenum;
  pthread_mutex_unlock(&mutexPool);
  return alivenum;
}

template <typename T>
void yazi::ThreadPool<T>::ThreadExit() {
  pthread_t tid = pthread_self();
  for (int i = 0; i < maxnum; i++) {
    if (threadIDs[i] == tid) {
      threadIDs[i] = 0;
      cout << "threadExit() called, " << to_string(tid) << "exiting...\n";
      break;
    }
  }
  pthread_exit(NULL);
}
