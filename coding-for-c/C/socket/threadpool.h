#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct ThreadPool ThreadPool;
// create the thread pool and init it
ThreadPool *ThreadPoolCreate(int max, int min, int queueSize);

// destroy the thread pool
int ThreadPoolDestroy(ThreadPool *pool);

// add tasks to the thread pool
void ThreadPoolAdd(ThreadPool *pool, void (*func)(void *), void *arg);

// get the number of working threads in the thread pool

int ThreadPoolBusyNum(ThreadPool *pool);

// get the number of living threads in the thread pool
int ThreadPoolAliveNum(ThreadPool *pool);

// the working function
void *worker(void *arg);

// the manager function
void *manager(void *arg);

// thread exit function
void ThreadExit(ThreadPool *pool);
