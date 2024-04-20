// 互斥锁
/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <sys/stat.h> */
/* #include <unistd.h>//sleep() */
/* #include <pthread.h> */
/* #define MAX 50 */
/* int number; */
/* pthread_mutex_t mutex; */
/* void* funcA(void* arg) */
/* { */
/*     for (int i = 0; i < MAX; ++i) { */
/*         //对公共资源加锁 */
/*         pthread_mutex_lock(&mutex); */
/*         int cur = number; */
/*         cur++; */
/*         usleep(10); */
/*         number = cur; */
/*         //解锁 */
/*         pthread_mutex_unlock(&mutex); */
/*         printf("Thread A, id = %lu, number = %d\n", pthread_self(),number);
 */
/*     } */
/*     return NULL; */
/* } */
/* void* funcB(void* arg) */
/* { */
/*     for (int i = 0; i < MAX; ++i) { */
/*         pthread_mutex_lock(&mutex); */
/*         int cur = number; */
/*         cur++; */
/*         usleep(10); */
/*         number = cur; */
/*         pthread_mutex_unlock(&mutex); */
/*         printf("Thread B, id = %lu, number = %d\n", pthread_self(),number);
 */
/*     } */
/*     return NULL; */
/* } */
/* int main(int argc, char *argv[]) */
/* { */
/*     pthread_t p1,p2; */
/*     pthread_mutex_init(&mutex, NULL); */
/*     /1* 创建两个子线程 *1/ */
/*     pthread_create(&p1,NULL,funcA,NULL); */
/*     pthread_create(&p2,NULL,funcB,NULL); */

/*     //阻塞，资源回收 */
/*     pthread_join(p1, NULL); */
/*     pthread_join(p2, NULL); */

/*     pthread_mutex_destroy(&mutex); */
/*     return 0; */
/* } */

// 读写锁
// 三个写资源线程，每个线程对共享资源进行累加操作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// sleep()
#include <pthread.h>
#include <unistd.h>
#define MAX 50
int number;
pthread_rwlock_t rwlock;

void *readNum(void *arg) {
  for (int i = 0; i < MAX; ++i) {
    // 对公共资源加锁
    pthread_rwlock_rdlock(&rwlock);
    printf("Thread read, id = %lu, number = %d\n", pthread_self(), number);
    // 解锁
    pthread_rwlock_unlock(&rwlock);
    usleep(rand() % 5);
  }
  return NULL;
}

void *writeNum(void *arg) {
  for (int i = 0; i < MAX; ++i) {
    pthread_rwlock_wrlock(&rwlock);
    int cur = number;
    cur++;
    usleep(10);
    number = cur;
    pthread_rwlock_unlock(&rwlock);
    printf("Thread write, id = %lu, number = %d\n", pthread_self(), number);
    usleep(rand() % 5);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t p1[5], p2[3];
  pthread_rwlock_init(&rwlock, NULL);
  /* 创建子线程 */
  for (int i = 0; i < 5; i++) {
    pthread_create(&p1[i], NULL, readNum, NULL);
  }
  for (int i = 0; i < 3; i++) {
    pthread_create(&p2[i], NULL, writeNum, NULL);
  }

  // 阻塞，资源回收
  for (int i = 0; i < 5; i++) {
    pthread_join(p1[i], NULL);
  }
  for (int i = 0; i < 3; i++) {
    pthread_join(p2[i], NULL);
  }

  pthread_rwlock_destroy(&rwlock);
  return 0;
}
