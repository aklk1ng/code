#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct ThreadPool ThreadPool;
//创建线程池并初始化
ThreadPool* ThreadPoolCreate(int max, int min, int queueSize);

//销毁线程池
int ThreadPoolDestroy(ThreadPool* pool);


//给线程池添加任务
void ThreadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg);

//当前线程池的工作的线程数

int ThreadPoolBusyNum(ThreadPool* pool);

//线程池中的存活的线程的个数
int ThreadPoolAliveNum(ThreadPool* pool);

//工作函数
void* worker(void* arg);


//管理函数
void* manager(void* arg);

//线程退出函数
void ThreadExit(ThreadPool* pool);

