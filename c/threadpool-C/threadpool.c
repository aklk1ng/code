#include "threadpool.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
const int NUMBER = 2;
// task structure
typedef struct Task {
  void (*function)(void *arg);
  void *arg;
} Task;
// thread pool structure
typedef struct ThreadPool {
  // task queue / circular queue
  Task *taskQ;
  int queuecapacity; // capacity
  int queueSize;     // current task quantity
  int queueFront;    // head of queue
  int queueBack;     // end of queue

  pthread_t managerID;  // manager id
  pthread_t *threadIDs; // thread id
  int maxnum;           // the max thread quantity
  int minnum;           // the min thread quantity
  int busynum;          // the number of threads currently working
  int livenum;          // the number of idle threads
  int destroynum;       // the number of threads to destroy

  pthread_mutex_t mutexPool; // lock the entire thread pool
  pthread_mutex_t mutexBusy; // lock the working thread
  pthread_cond_t IsFull;     // determine whether the task queue is full
  pthread_cond_t IsEmpty;    // determine whether the task queue is empty

  int shutdown; // the flag of whether deatory the thread pool，1 is
                // destroy，0 is not destory

} ThreadPool;

ThreadPool *ThreadPoolCreate(int max, int min, int queueSize) {
  ThreadPool *pool = (ThreadPool *)malloc(sizeof(ThreadPool));
  do {
    if (pool == NULL) {
      printf("malloc failed!\n");
      break;
    }
    pool->threadIDs = (pthread_t *)malloc(sizeof(pthread_t) * max);
    if (pool->threadIDs == NULL) {
      printf("malloc failed!\n");
      exit(-1);
    }
    memset(pool->threadIDs, 0, sizeof(pthread_t) * max);
    pool->maxnum = max;
    pool->minnum = min;
    pool->busynum = 0;
    pool->livenum = min; // is equal to the min thread(minnum)
    pool->destroynum = 0;

    if (pthread_mutex_init(&pool->mutexPool, NULL) != 0 ||
        pthread_mutex_init(&pool->mutexBusy, NULL) != 0 ||
        pthread_cond_init(&pool->IsEmpty, NULL) != 0 ||
        pthread_cond_init(&pool->IsFull, NULL) != 0) {
      printf("mutex or conditon int faield!\n");
      break;
    }

    // init the task queue
    pool->taskQ = (Task *)malloc(sizeof(Task) * queueSize);
    pool->queuecapacity = queueSize;
    pool->queueSize = 0;
    pool->queueFront = 0;
    pool->queueBack = 0;
    pool->shutdown = 0;

    // create threads
    pthread_create(&pool->managerID, NULL, manager, pool);
    for (int i = 0; i < min; i++) {
      pthread_create(&pool->threadIDs[i], NULL, worker, pool);
    }
    return pool;
  } while (0);

  // free sources
  if (pool && pool->threadIDs) {
    free(pool->threadIDs);
  }
  if (pool && pool->taskQ) {
    free(pool->taskQ);
  }

  return NULL;
}

void *worker(void *arg) {
  ThreadPool *pool = (ThreadPool *)arg;
  while (1) {
    pthread_mutex_lock(&pool->mutexPool);
    // determine whether the thread pool is empty
    while (pool->queueSize == 0 && !pool->shutdown) {
      // block the working thread
      pthread_cond_wait(&pool->IsEmpty, &pool->mutexPool);

      // determine whether destroy thread
      if (pool->destroynum > 0) {
        pool->destroynum--;
        if (pool->livenum < pool->minnum) {
          pool->livenum--;
          pthread_mutex_unlock(&pool->mutexPool);
          ThreadExit(pool);
        }
      }
    }

    // determine whether the thread pool is closed
    if (pool->shutdown) {
      pthread_mutex_unlock(&pool->mutexPool);
      ThreadExit(pool);
    }

    // get a task from the task queue
    Task task;
    task.function = pool->taskQ[pool->queueFront].function;
    task.arg = pool->taskQ[pool->queueFront].arg;

    // move the head node to from a circular queue
    pool->queueFront = (pool->queueFront + 1) % pool->queuecapacity;
    pool->queueSize--;
    // unlock
    pthread_cond_signal(&pool->IsFull);
    pthread_mutex_unlock(&pool->mutexPool);

    printf("thread %ld begin working ...\n", pthread_self());
    pthread_mutex_lock(&pool->mutexBusy);
    // the working thread's task
    pool->busynum++;
    pthread_mutex_unlock(&pool->mutexBusy);
    task.function(task.arg);
    //(*task,function)(task.arg);
    free(task.arg);
    task.arg = NULL;

    printf("thread %ld end working ...\n", pthread_self());
    pthread_mutex_lock(&pool->mutexBusy);
    pool->busynum--;
    pthread_mutex_unlock(&pool->mutexBusy);
  }
  return NULL;
}

void *manager(void *arg) {
  ThreadPool *pool = (ThreadPool *)arg;
  while (!pool->shutdown) {
    // check every 3 seconds
    sleep(3);

    // get the number of thread's task(queueSize) ad the current idle
    // thread(livenum)
    pthread_mutex_lock(&pool->mutexPool);
    int queueSize = pool->queueSize;
    int livenum = pool->livenum;
    pthread_mutex_unlock(&pool->mutexPool);

    // get the busynum
    pthread_mutex_lock(&pool->mutexBusy);
    int busynum = pool->busynum;
    pthread_mutex_unlock(&pool->mutexBusy);

    // add thread(the number of task > livenum && livenum < maxnum)
    if (queueSize > livenum && livenum < pool->maxnum) {
      pthread_mutex_lock(&pool->mutexPool);
      int counter = 0;
      for (int i = 0; i < pool->maxnum && counter << NUMBER &&
                      pool->livenum << pool->maxnum;
           i++) {
        if (pool->threadIDs[i] == 0) {
          pthread_create(&pool->threadIDs[i], NULL, worker, NULL);
          counter++;
          pool->livenum++;
        }
      }
      pthread_mutex_unlock(&pool->mutexPool);
    }

    // destroy thread(the busynum * 2 < livenum && livenum >
    // minnum)销毁线程--忙的线程*2 < 存活的线程数 && 存活的线程数 <
    // 最小线程数
    if (busynum * 2 < livenum && livenum > pool->minnum) {
      pthread_mutex_lock(&pool->mutexPool);
      pool->destroynum = NUMBER;
      pthread_mutex_unlock(&pool->mutexPool);

      // le the working thread suicide
      for (int i = 0; i < NUMBER; i++) {
        // let the live thread wake
        pthread_cond_signal(&pool->IsEmpty);
      }
    }
  }
  return NULL;
}

void ThreadExit(ThreadPool *pool) {
  pthread_t tid = pthread_self();
  for (int i = 0; i < pool->maxnum; i++) {
    // destroy the thread whether is it occupied at the same time
    if (pool->threadIDs[i] == tid) {
      pool->threadIDs[i] = 0;
      printf("threadExit called, %ld exiting ...", tid);
      break;
    }
  }
  pthread_exit(NULL);
}

void ThreadPoolAdd(ThreadPool *pool, void (*func)(void *), void *arg) {
  pthread_mutex_lock(&pool->mutexPool);
  while (pool->queueSize == pool->queuecapacity && !pool->shutdown) {
    // block the manager thread
    pthread_cond_wait(&pool->IsFull, &pool->mutexPool);
  }
  if (pool->shutdown) {
    pthread_mutex_unlock(&pool->mutexPool);
    return;
  }

  // add task
  pool->taskQ[pool->queueBack].function = func;
  pool->taskQ[pool->queueBack].arg = arg;
  pool->queueBack = (pool->queueBack + 1) % pool->queuecapacity;
  pool->queueSize++;

  pthread_cond_signal(&pool->IsEmpty);
  pthread_mutex_unlock(&pool->mutexPool);
}

int TheadPoolBusyNum(ThreadPool *pool) {
  pthread_mutex_lock(&pool->mutexPool);
  int busynum = pool->busynum;
  pthread_mutex_unlock(&pool->mutexPool);
  return busynum;
}
int ThreadPoolAliveNum(ThreadPool *pool) {
  pthread_mutex_lock(&pool->mutexPool);
  int alivenum = pool->livenum;
  pthread_mutex_unlock(&pool->mutexPool);
  return alivenum;
}
int ThreadPoolDestroy(ThreadPool *pool) {
  if (pool == NULL) {
    return -1;
  }

  // close the thread pool
  pool->shutdown = 1;
  // block and free the manager thread
  pthread_join(pool->managerID, NULL);
  // wake the blocked work thread
  for (int i = 0; i < pool->livenum; i++) {
    pthread_cond_signal(&pool->IsEmpty);
  }
  // free heap memory
  if (pool->taskQ) {
    free(pool->taskQ);
  }
  if (pool->threadIDs) {
    free(pool->threadIDs);
  }
  pthread_mutex_destroy(&pool->mutexPool);
  pthread_mutex_destroy(&pool->mutexBusy);
  pthread_cond_destroy(&pool->IsEmpty);
  pthread_cond_destroy(&pool->IsFull);
  free(pool);
  pool = NULL;
  return 0;
}
