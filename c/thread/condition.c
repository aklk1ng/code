#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 利用互斥锁与条件变量对线程进行管理，可以减少手动的对程序某些情况的判断
pthread_cond_t cond;
pthread_mutex_t mutex;

typedef struct Node {
  int number;
  struct Node *next;
} Node;

Node *head = NULL;

void *producer(void *arg) {
  while (1) {
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
    pthread_cond_broadcast(&cond);
    sleep(rand() % 3);
  }
  return NULL;
}

void *consumer(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    while (head == NULL) {
      // 线程阻塞
      pthread_cond_wait(&cond, &mutex);
    }
    Node *node = head;
    printf("consumer id: %ld,number: %d\n", pthread_self(), node->number);
    head = head->next;
    free(node);
    pthread_mutex_unlock(&mutex);
    sleep(rand() % 3);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

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
  pthread_cond_destroy(&cond);
  return 0;
}
