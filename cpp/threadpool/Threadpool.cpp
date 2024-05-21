#include "Threadpool.h"
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <string>
#include <unistd.h>

template <typename T>
yazi::ThreadPool<T>::ThreadPool(int max, int min) {
    // instance the task queue
    do {
        taskQ = new TaskQueue<T>;
        if (taskQ == nullptr) {
            std::cout << "new failed!" << std::endl;
            break;
        }
        threadIDs = new pthread_t[max];
        if (threadIDs == nullptr) {
            std::cout << "new failed!" << std::endl;
            break;
        }
        memset(threadIDs, 0, sizeof(pthread_t) * max);
        maxnum = max;
        minnum = min;
        busynum = 0;
        livenum = min;
        destroynum = 0;

        if (pthread_mutex_init(&mutexPool, NULL) != 0 ||
            pthread_cond_init(&IsEmpty, NULL) != 0) {
            std::cout << "mutex or conditon int faield!" << std::endl;
            break;
        }

        shutdown = false;

        // create thread
        pthread_create(&managerID, NULL, manager, this);
        for (int i = 0; i < min; i++) {
            pthread_create(&threadIDs[i], NULL, worker, this);
        }
        return;
    } while (0);

    // free resource
    if (threadIDs) {
        delete[] (threadIDs);
    }
    if (taskQ) {
        delete[] (taskQ);
    }
}

template <typename T>
yazi::ThreadPool<T>::~ThreadPool() {
    shutdown = true;
    pthread_join(managerID, NULL);
    for (int i = 0; i < livenum; i++) {
        pthread_cond_signal(&IsEmpty);
    }
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
        // check current task queue whether is empty
        while (pool->taskQ->taskNumber() == 0 && !pool->shutdown) {
            pthread_cond_wait(&pool->IsEmpty, &pool->mutexPool);

            if (pool->destroynum > 0) {
                pool->destroynum--;
                if (pool->livenum < pool->minnum) {
                    pool->livenum--;
                    pthread_mutex_unlock(&pool->mutexPool);
                    pool->ThreadExit();
                }
            }
        }

        if (pool->shutdown) {
            pthread_mutex_unlock(&pool->mutexPool);
            pool->ThreadExit();
        }

        // take a task
        Task<T> task = pool->taskQ->takeTask();
        // unlock
        pool->busynum++;
        pthread_mutex_unlock(&pool->mutexPool);

        std::cout << "thread " << std::to_string(pthread_self())
                  << " begin working" << std::endl;
        task.function(task.arg);
        delete task.arg;
        task.arg = nullptr;

        std::cout << "thread " << std::to_string(pthread_self())
                  << " end working" << std::endl;
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
        sleep(3);

        pthread_mutex_lock(&pool->mutexPool);
        int queueSize = pool->taskQ->taskNumber();
        int livenum = pool->livenum;
        int busynum = pool->busynum;
        pthread_mutex_unlock(&pool->mutexPool);

        if (queueSize > livenum && livenum < pool->maxnum) {
            pthread_mutex_lock(&pool->mutexPool);
            int counter = 0;
            for (int i = 0; i < pool->maxnum && counter <= NUMBER &&
                            pool->livenum <= pool->maxnum;
                 i++) {
                if (pool->threadIDs[i] == 0) {
                    pthread_create(&pool->threadIDs[i], NULL, worker, NULL);
                    counter++;
                    pool->livenum++;
                }
            }
            pthread_mutex_unlock(&pool->mutexPool);
        }

        if (busynum * 2 < livenum && livenum > pool->minnum) {
            pthread_mutex_lock(&pool->mutexPool);
            pool->destroynum = NUMBER;
            pthread_mutex_unlock(&pool->mutexPool);

            for (int i = 0; i < NUMBER; i++) {
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
    // add task
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
            std::cout << "threadExit() called, " << std::to_string(tid)
                      << "exiting...\n";
            break;
        }
    }
    pthread_exit(NULL);
}
