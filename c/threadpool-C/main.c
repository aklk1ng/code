#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "threadpool.h"
void taskFunc(void *arg) {
  int num = *(int *)arg;
  printf("thread %ld is working, number is %d\n", pthread_self(), num);
  sleep(1);
}
int main(int argc, char *argv[]) {
  // create a threadpool
  ThreadPool *pool = ThreadPoolCreate(10, 3, 100);
  for (int i = 0; i < 100; i++) {
    int *num = (int *)malloc(sizeof(int));
    *num = i + 100;
    ThreadPoolAdd(pool, taskFunc, num);
  }

  // let the main thread do the work
  sleep(20);
  ThreadPoolDestroy(pool);
  return 0;
}
