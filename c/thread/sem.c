// 生产者与消费者模型,使用信号量进行对线程的管理，如果资源数大于1,则要使用线程同步
#include <pthread.h>
#include <semaphore.h> //信号量函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 信号量
sem_t semp; // producer
sem_t semc; // consumer

pthread_mutex_t mutex;

typedef struct Node {
  int number;
  struct Node *next;
} Node;

Node *head = NULL;

void *producer(void *arg) {
  while (1) {
    sem_wait(&semp);
    pthread_mutex_lock(&mutex);
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
      printf("malloc failed!\n");
      exit(-1);
    }
    newnode->number = rand() % 1000;
    newnode->next = head;
    head = newnode;
    printf("producer id: %ld,number: %d\n", pthread_self(), newnode->number);
    pthread_mutex_unlock(&mutex);
    // 将信号量传给consumer
    sem_post(&semc);
    sleep(rand() % 3);
  }
  return NULL;
}

void *consumer(void *arg) {
  while (1) {
    sem_wait(&semc);
    pthread_mutex_lock(&mutex);
    Node *node = head;
    printf("consumer id: %ld,number: %d\n", pthread_self(), node->number);
    head = head->next;
    free(node);
    pthread_mutex_unlock(&mutex);
    // 通知producer
    sem_post(&semp);
    sleep(rand() % 3);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  // 此时资源数为5,需要其他的锁进行保护
  sem_init(&semp, 0, 5);
  sem_init(&semc, 0, 0);

  pthread_mutex_init(&mutex, NULL);

  pthread_t t1[5], t2[5];
  for (int i = 0; i < 5; i++) {
    pthread_create(&t1[i], NULL, producer, NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_create(&t2[i], NULL, consumer, NULL);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(t1[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(t2[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  sem_destroy(&semp);
  sem_destroy(&semc);
  return 0;
}
