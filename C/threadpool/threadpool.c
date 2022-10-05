#include "threadpool.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //任务结构体
#include <unistd.h>
const int NUMBER = 2;
typedef struct Task
{
    void (*function)(void* arg);
    void* arg;
}Task;
//线程池结构体
typedef struct ThreadPool
{
    //任务队列
    Task* taskQ;
    int queuecapacity;//容量
    int queueSize;//当前任务个数
    int queueFront;//队头
    int queuBack;//队尾
    
    pthread_t managerID;//管理者id
    pthread_t* threadIDs;//工作的线程id
    int maxnum;//最大线程数量
    int minnum;//最小线程数量
    int busynum;//处于工作的线程
    int livenum;//存活的线程
    int destroynum;//要销毁的线程

    pthread_mutex_t mutexPool;//对整个线程池进行加锁
    pthread_mutex_t mutexBusy;//对处于工作的线程进行加锁
    pthread_cond_t IsFull;//任务队列是否满了
    pthread_cond_t IsEmpty;//任务队列是否空了

    int shutdown;//销毁线程池的标志位，1为销毁，0为不销毁

}ThreadPool;


ThreadPool* ThreadPoolCreate(int max, int min, int queueSize)
{
    ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));
    do {
        if(pool == NULL) {
            printf("malloc failed!\n");
            break;
        }
        pool->threadIDs = (pthread_t*)malloc(sizeof(pthread_t) * max);
        if(pool->threadIDs == NULL) {
            printf("malloc failed!\n");
            exit(-1);
        }
        memset(pool->threadIDs, 0, sizeof(pthread_t) * max);
        pool->maxnum = max;
        pool->minnum = min;
        pool->busynum = 0;
        pool->livenum = min;//与最小的线程相等
        pool->destroynum = 0;

        if(
                pthread_mutex_init(&pool->mutexPool,NULL) != 0 ||
                pthread_mutex_init(&pool->mutexBusy,NULL) != 0 ||
                pthread_cond_init(&pool->IsEmpty,NULL) != 0 ||
                pthread_cond_init(&pool->IsFull,NULL) != 0
          ) {
            printf("mutex or conditon int faield!\n");
            break;
        }

        //任务队列的初始化
        pool->taskQ = (Task*)malloc(sizeof(Task) * queueSize);
        pool->queuecapacity = queueSize;
        pool->queueSize = 0;
        pool->queueFront = 0;
        pool->queuBack = 0;
        pool->shutdown = 0;

        //创建线程
        pthread_create(&pool->managerID, NULL, manager, pool);
        for (int i = 0; i < min; i++) {
            pthread_create(&pool->threadIDs[i], NULL, worker, pool);
        }
        return pool;
     } while(0);

    //释放资源
    if(pool && pool->threadIDs) {
        free(pool->threadIDs);
    }
    if(pool && pool->taskQ) {
        free(pool->taskQ);
    }

    return NULL;
}

void* worker(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;
    while (1) {
        pthread_mutex_lock(&pool->mutexPool);
        //当前任务队列是否为空
        while (pool->queueSize == 0 && !pool->shutdown) {
            //阻塞工作线程
            pthread_cond_wait(&pool->IsEmpty,&pool->mutexPool);

            //判断是否要销毁线程
            if(pool->destroynum > 0) {
                pool->destroynum--;
                if(pool->livenum < pool->minnum) {
                    pool->livenum--;
                    pthread_mutex_unlock(&pool->mutexPool);
                    ThreadExit(pool);
                }
            }
        }

        //判断线程池u是否被关闭
        if(pool->shutdown) {
            pthread_mutex_unlock(&pool->mutexPool);
            ThreadExit(pool);
        }

        //从任务队列中取出一个任务
        Task task;
        task.function = pool->taskQ[pool->queueFront].function;
        task.arg = pool->taskQ[pool->queueFront].arg;

        //移动头节点,形成循环队列
        pool->queueFront = (pool->queueFront +1) % pool->queuecapacity;
        pool->queueSize--;
        //解锁
        pthread_cond_signal(&pool->IsFull);
        pthread_mutex_unlock(&pool->mutexPool);

        printf("thread %ld begin working ...\n", pthread_self());
        pthread_mutex_lock(&pool->mutexBusy);
        pool->busynum++;
        task.function(task.arg);
        //(*task,function)(task.arg);
        free(task.arg);
        task.arg = NULL;
        
        printf("thread %ld end working ...\n", pthread_self());
        pthread_mutex_lock(&pool->mutexBusy);
        pool->busynum--;
        task.function(task.arg);
    }
    return NULL;
}

void* manager(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;
    while (!pool->shutdown) {
       //每隔3s检测一次
       sleep(3);

       //取出线程中任务的数量和当前线程的数量
        pthread_mutex_lock(&pool->mutexPool);
        int queueSize = pool->queueSize;
        int livenum = pool->livenum;
        pthread_mutex_unlock(&pool->mutexPool);

        //取出忙的线程的数量
        pthread_mutex_lock(&pool->mutexBusy);
        int busynum = pool->busynum;
        pthread_mutex_unlock(&pool->mutexBusy);

        //添加线程--任务的个数>存活的个数&&存活的线程数<最大线程数
        if(queueSize > livenum && livenum < pool->maxnum) {
            pthread_mutex_lock(&pool->mutexPool);
            int counter = 0;
            for (int i = 0; i < pool->maxnum && counter << NUMBER && pool->livenum << pool->maxnum; i++) {
                if(pool->threadIDs[i] == 0) {
                    pthread_create(&pool->threadIDs[i], NULL, worker, NULL);
                    counter++;
                    pool->livenum++;
                }
            }
            pthread_mutex_unlock(&pool->mutexPool);
        }

        //销毁线程--忙的线程*2 < 存活的线程数 && 存活的线程数 < 最小线程数
        if(busynum * 2 < livenum && livenum > pool->minnum) {
            pthread_mutex_lock(&pool->mutexPool);
            pool->destroynum = NUMBER;
            pthread_mutex_unlock(&pool->mutexPool);

            //让工作的线程自杀
            for (int i = 0; i < NUMBER; i++) {
                //对空闲的线程进行唤醒
                pthread_cond_signal(&pool->IsEmpty);
            }
        }
    }
    return NULL;
}

void ThreadExit(ThreadPool* pool)
{
   pthread_t tid = pthread_self();
   for (int i = 0; i < pool->maxnum; i++) {
       //对线程是否同时占用进行销毁线程
       if(pool->threadIDs[i] == tid) {
           pool->threadIDs[i] = 0;
           printf("threadExit called, %ld exiting ...", tid);
           break;
       }
   }
   pthread_exit(NULL);
}

void ThreadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg)
{
    pthread_mutex_lock(&pool->mutexPool);
    while (pool->queueSize == pool->queuecapacity && !pool->shutdown) {
        //阻塞生产者线程
        pthread_cond_wait(&pool->IsFull, &pool->mutexPool);
    }
    if(pool->shutdown) {
        pthread_mutex_unlock(&pool->mutexPool);
        return;
    }

    //添加任务
    pool->taskQ[pool->queuBack].function = func;
    pool->taskQ[pool->queuBack].arg = arg;
    pool->queuBack = (pool->queuBack + 1) % pool->queuecapacity;
    pool->queueSize++;

    pthread_cond_signal(&pool->IsEmpty);
    pthread_mutex_unlock(&pool->mutexPool);

}

int TheadPoolBusyNum(ThreadPool* pool)
{}
int ThreadPoolAliveNum(ThreadPool* pool)
{}
