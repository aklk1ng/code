#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct ThreadPool ThreadPool;
// create the thread pool and init
ThreadPool* ThreadPoolCreate(int max, int min, int queueSize);

// destory the thread pool
int ThreadPoolDestroy(ThreadPool* pool);


// add task to the thread pool
void ThreadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg);

// get the number of the current working thread

int ThreadPoolBusyNum(ThreadPool* pool);

// get the number of the idle thread
int ThreadPoolAliveNum(ThreadPool* pool);

// the work function
void* worker(void* arg);


// the manager function
void* manager(void* arg);

// the thread exits function
void ThreadExit(ThreadPool* pool);

