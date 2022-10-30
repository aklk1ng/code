#include "threadpool.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void taskFunc(void* arg)
{
    int num = *(int*)arg;
    printf("thread %ld is working, number is %d\n", pthread_self(), num);
    sleep(1);
}
int main(int argc, char *argv[])
{
    //创建线程池
    ThreadPool* pool = ThreadPoolCreate(10, 3, 100);
    for (int i = 0; i < 100; i++) {
        int* num = (int*)malloc(sizeof(int));
        *num = i +100;
        ThreadPoolAdd(pool, taskFunc, num);
    } 

    //让主线程确保完成任务
    sleep(20);
    ThreadPoolDestroy(pool);
    return 0;
}
