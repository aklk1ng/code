#include"TaskQueue.h"
template <typename T>
TaskQueue<T>::TaskQueue() {
    pthread_mutex_init(&mutex, NULL);
}
template <typename T>
TaskQueue<T>::~TaskQueue() {
    pthread_mutex_destroy(&mutex);
}
template <typename T>
void TaskQueue<T>::addTask(Task<T> task) {
    pthread_mutex_lock(&mutex);
    taskQ.push(task);
    pthread_mutex_unlock(&mutex);
}
template <typename T>
void TaskQueue<T>::addTask(callback f, void* arg) {
    pthread_mutex_lock(&mutex);
    taskQ.push(Task<T>(f, arg));
    pthread_mutex_unlock(&mutex);
}

template <typename T>
Task<T> TaskQueue<T>::takeTask() {
    Task<T> t;
    pthread_mutex_lock(&mutex);
    if(taskQ.size() > 0) {
        t = taskQ.front();
        taskQ.pop();
    }
    pthread_mutex_unlock(&mutex);
    return t;
}
