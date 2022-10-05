#include "threadpool.h"
//任务结构体
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
    int bustnum;//处于工作的线程
    int livenum;//存活的线程
    int destroynum;//要销毁的线程

    pthread_mutex_t mutexPool;//对整个线程池进行加锁
    pthread_mutex_t mutexBusy;//对处于工作的线程进行加锁
    pthread_cond_t IsFull;//任务队列是否满了
    pthread_cond_t IsEmpty;//任务队列是否空了

    int shutdown;//销毁线程池的标志位，1为销毁，0为不销毁

}ThreadPool;

ThreadPool* ThreadPoolCreate(int max, int min, int queuesize)
{
    ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));
    if(pool == NULL) {
        printf("malloc failed!\n");
        exit(-1);
    }
}
